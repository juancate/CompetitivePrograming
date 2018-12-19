#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cassert>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <complex>

#define D(x) cerr << #x << " = " << (x) << endl;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

const int maxn = 100010;
const int mod = INF + 7;

int pset[maxn], rank[maxn], size[maxn];
bool used[maxn];

void init(int n) {
  for(int i = 0; i < n; i++) {
    pset[i] = i; rank[i] = 0; size[i] = 1;
  }
}

int find(int x) {
  return (x == pset[x])? x : pset[x] = find(pset[x]);
}

void unite(int x, int y) {
  int px = find(x);
  int py = find(y);

  if(px == py)
    return;

  if(rank[px] < rank[py]) {
    pset[px] = py;
    size[py] += size[px];
  }
  else {
    pset[py] = px;
    size[px] += size[py];
    if(rank[px] == rank[py])
      rank[px]++;
  }
}

int64 get_size(int x) {
  int px = find(x);
  if(!used[px]) {
    used[px] = true;
    return (int64)size[px];
  }
  return 1LL;
}

int main() {
  int t, n, m;
  scanf("%d", &t);

  while(t--) {
    scanf("%d%d", &n, &m);

    init(n);
    memset(used, 0, n*sizeof(bool));
    for(int i = 0; i < m; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      a--; b--;
      unite(a, b);
    }

    int scapes = 0;
    int64 capitans = 1;

    for(int i = 0; i < n; i++) {
      int px = find(i);
      if(!used[px]) {
        scapes++;
        capitans = (capitans * get_size(px)) % mod;
      }
    }
    printf("%d %lld\n", scapes, capitans);
  }

  return 0;
}

