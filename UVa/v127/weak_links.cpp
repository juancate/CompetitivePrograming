#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n, m, dfs_low[N], dfs_num[N], dfs_parent[N];
int dfs_cnt, dfs_root, root_children;
vector<int> g[N];
vector<pair<int,int>> ans;

void find_bridges(int u) {
  dfs_low[u] = dfs_num[u] = dfs_cnt++;
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    if (dfs_num[v] == -1) {
      dfs_parent[v] = u;
      if (u == dfs_root) root_children++;
      find_bridges(v);
      if (dfs_low[v] > dfs_num[u])
        ans.push_back(make_pair(min(u, v), max(v, u)));
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    else if (v != dfs_parent[u])
      dfs_low[u] = min(dfs_low[u], dfs_num[v]);
  }
}

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> n >> m) {
    if ((n|m) == 0)
      break;

    for (int i = 0; i < n; i++)
      g[i].clear();

    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }

    ans.clear();
    dfs_cnt = 0;
    for (int i = 0; i < n; i++)
      dfs_num[i] = -1, dfs_low[i] = 0, dfs_parent[i] = 0;
    for (int i = 0; i < n; i++)
      if (dfs_num[i] < 0) {
        dfs_root = i;
        root_children = 0;
        find_bridges(i);
      }

    sort(ans.begin(), ans.end());
    cout << ans.size();
    for (int i = 0; i < ans.size(); i++)
      cout << ' ' << ans[i].first << ' ' << ans[i].second;
    cout << '\n';
  }

  return 0;
}
