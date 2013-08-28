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
#include <set>
#include <map>
#include <algorithm>

#define D(x) cerr << #x << " = " << x << endl
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

using namespace std;

const int maxn = 2010;
const int mod = INF+7;

int p[maxn], rank[maxn];

int init(int n) {
  for(int i = 0; i < n; i++) {
    p[i] = i;
    rank[i] = 0;
  }
}

int find(int x) {
  return (x == p[x])? x : p[x] = find(p[x]);
}

void unite(int x, int y) {
  int px = find(x);
  int py = find(y);

  if(px == py)
    return;

  if(rank[px] < rank[py]) {
    p[px] = py;
  }
  else {
    p[py] = px;
    if(rank[px] == rank[py])
      rank[px]++;
  }
}

int count_sets(int n) {
  set<int> s;
  for(int i = 0; i < n; i++)
    s.insert(find(i));
  return s.size();
}

long long mulmod(long long a, long long b, long long c) {
  long long x = 0, y = a % c;

  while(b > 0) {
    if(b & 1) x = (x + y) % c;
    y = (y << 1) % c;
    b >>= 1;
  }
  return x;
}

long long mod_pow(long long a, long long b, long long c) {
  long long x = 1LL, y = a;

  while(b > 0) {
    if(b & 1) x = mulmod(x, y, c);
    y = mulmod(y, y, c);
    b >>= 1;
  }

  return x;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m >> k;

  init(n);

  for(int i = 0; i < n; i++) {
    int start = i;
    int end = i + k - 1;
    if(end >= n) break;
    while(start <= end) {
      unite(start, end);
      start++;
      end--;
    }
  }
  int cnt = count_sets(n);

  cout << mod_pow(m, cnt, mod) << endl;

  return 0;
}

