#include <bits/stdc++.h>

using namespace std;

bool has_cycle;
int V, n, m, cycle_len;
map<int, int> M;
vector< vector<int> > g;
vector<int> in_degree, dfs_parent, dfs_num;

void dfs_check(int u) {
  dfs_num[u] = 0;
  cycle_len++;
  for (int i = 0; i < (int)g[u].size(); i++) {
    int v = g[u][i];
    if (dfs_num[v] == -1) {
      dfs_parent[v] = u;
      dfs_check(v);
    }
    else if (dfs_num[v] == 0) {
      if (v != dfs_parent[u])
        has_cycle = true;
    }
    // else if (dfs_num[v] == 1) forward edge
  }
  dfs_num[u] = 1;
}

bool solve() {
  dfs_num.assign(V, -1);
  dfs_parent.assign(V, -1);
  for (int u = 0; u < V; u++) {
    int in = in_degree[u];

    if (in > 2)
      return false;

    if (dfs_num[u] == -1) {
      cycle_len = 0;
      has_cycle = false;
      dfs_check(u);

      if (has_cycle && cycle_len != n)
        return false;
    }
  }

  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> n >> m) {
    if ((n|m) == 0)
      break;

    V = 0;
    M.clear();
    g.clear();

    for (int i = 0; i < m; i++) {
      int a, b, u, v;
      cin >> a >> b;

      if (!M.count(a)) {
        M[a] = V++;
        g.push_back(vector<int>());
      }
      if (!M.count(b)) {
        M[b] = V++;
        g.push_back(vector<int>());
      }

      u = M[a];
      v = M[b];

      g[u].push_back(v);
      g[v].push_back(u);
    }

    in_degree.assign(V, 0);
    for (int i = 0; i < V; i++) {
      vector<int> & e = g[i];
      sort(e.begin(), e.end());
      e.resize(unique(e.begin(), e.end()) - e.begin());

      for (int i = 0; i < (int)e.size(); i++)
        in_degree[e[i]]++;
    }

    cout << (solve()? 'Y' : 'N') << endl;
  }

  return 0;
}
