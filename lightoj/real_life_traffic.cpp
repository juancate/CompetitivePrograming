#include <bits/stdc++.h>

#define foreach(it,v) for (__typeof((v).begin()) it=(v).begin(); it!=(v).end(); it++)

using namespace std;

// 1291 - Real Life Traffic
// Algorithm: Bridges, biconnected components

const int maxn = 10010;

int n, m, scc[maxn], bridge_count[maxn];
vector<int> g[maxn];
set<int> g2[maxn];
vector< pair<int,int> > briges;
bool visited[maxn];

int dfsNumberCounter, dfsRoot, rootChildren, components;
vector<int> dfs_num, dfs_low, dfs_parent;

void articulation_point_bridge(int u) {
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    if (dfs_num[v] < 0) {
      dfs_parent[v] = u;
      if (u == dfsRoot) rootChildren++;

      articulation_point_bridge(v);

      if (dfs_low[v] > dfs_num[u]) {
        briges.push_back(make_pair(min(u,v),max(u,v)));
        g2[u].erase(v);
        g2[v].erase(u);
      }
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    else if (v != dfs_parent[u])
      dfs_low[u] = min(dfs_low[u], dfs_num[v]);
  }
}

void dfs(int u) {
  if (visited[u])
    return;
  visited[u] = 1;
  scc[u] = components;

  foreach(v, g2[u])
    dfs(*v);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  for (int tc = 1; tc <= t; tc++) {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
      g[i].clear();
      g2[i].clear();
    }

    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);

      g2[u].insert(v);
      g2[v].insert(u);
    }

    briges.clear();

    dfsNumberCounter = 0;
    dfs_num.assign(n, -1);
    dfs_low.assign(n, 0);
    dfs_parent.assign(n, 0);

    for (int i = 0; i < n; i++)
      if (dfs_num[i] < 0) {
        dfsRoot = i;
        rootChildren = 0;
        articulation_point_bridge(i);
      }

    memset(visited, 0, sizeof(visited));
    memset(scc, 0, sizeof(scc));
    memset(bridge_count, 0, sizeof(bridge_count));

    components = 0;
    for (int i = 0; i < n; i++)
      if (!visited[i]) {
        dfs(i);
        components++;
      }

    int ans = 0;
    foreach(b, briges) {
      bridge_count[scc[b->first]]++;
      bridge_count[scc[b->second]]++;
    }

    for (int i = 0; i < components; i++)
      if (bridge_count[i] == 1)
        ans++;

    cout << "Case " << tc << ": ";
    cout << ((ans + 1) / 2) << '\n';
  }

  return 0;
}
