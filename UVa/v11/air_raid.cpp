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

// Algorithm: Bipartite Matchin, Min Path Cover in a DAG

int n, m, owner[256];
vector<int> g[256];
bool used[256];

int khun(int left) {
  if(used[left]) return 0;
  used[left] = true;
  for(int i = 0; i < g[left].size(); i++) {
    int right = g[left][i];
    if(owner[right] == -1 || khun(owner[right])) {
      owner[right] = left;
      return 1;
    }
  }
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);

  while(t--) {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      g[u].push_back(n+v);
    }
    int card = 0;
    memset(owner, -1, sizeof owner);
    for(int left = 1; left <= n; left++) {
      memset(used, 0, sizeof used);
      card += khun(left);
    }
    printf("%d\n", n-card);

    for(int i = 1; i <= n; i++)
      g[i].clear();
  }

  return 0;
}

