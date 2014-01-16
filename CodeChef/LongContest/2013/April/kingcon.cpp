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

const int maxn = 3010;

int n;
vector<int> g[maxn];

int dfs_num[maxn], dfs_low[maxn], dfs_parent[maxn];
int dfsNumberCounter, dfsRoot, rootChildren;
bool articulation_vertex[maxn];

void articulationPointAndBridge(int u) {
  int j, v;

  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
  for(j = 0; j < g[u].size(); j++) {
    v = g[u][j];
    if(dfs_num[v] < 0) {
      dfs_parent[v] = u;
      if(u == dfsRoot) rootChildren++;

      articulationPointAndBridge(v);

      if(dfs_low[v] >= dfs_num[u])
        articulation_vertex[u] = true;
      //if(dfs_low[v] > dfs_num[u]) // bridge
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    else if(v != dfs_parent[u]) {
      dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
  }
}

void run_tarjan() {
  int i;

  dfsNumberCounter = 0;
  memset(dfs_num, -1, n * sizeof(int));
  memset(dfs_low, 0, n * sizeof(int));
  memset(dfs_parent, 0, n * sizeof(int));
  memset(articulation_vertex, 0, n);

  for(i = 0; i < n; i++)
    if(dfs_num[i] < 0) {
      dfsRoot = i;
      rootChildren = 0;
      articulationPointAndBridge(i);
      articulation_vertex[dfsRoot] = (rootChildren > 1);
    }
}

int main() {
  int t, m, k, i, a, b, ans;
  scanf("%d", &t);

  while(t--) {
    scanf("%d%d%d", &n, &m, &k);
    for(i = 0; i < m; i++) {
      scanf("%d%d", &a, &b);
      g[a].push_back(b);
      g[b].push_back(a);
    }

    run_tarjan();

    ans = count(articulation_vertex, articulation_vertex + n, 1);
    ans *= k;

    printf("%d\n", ans);

    for(i = 0; i < n; i++)
      g[i].clear();
  }
  return 0;
}

