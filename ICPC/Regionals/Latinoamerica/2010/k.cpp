#include <bits/stdc++.h>

#define foreach(it,v) for (__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)

using namespace std;

int n, m;
map<int, vector<int> > g;
map<int,int> seen;

bool dfs(int u, int p=-1) {
  if (seen[u] == 2)
    return false;

  seen[u]++;
  if (g[u].size() > 2)
    return false;

  if (g[u].empty())
    return true;

  if (p != -1) {
    if (p == g[u][0]) {
      if (g[u].size() > 1)
        return dfs(g[u][1], u);
      return true;
    }
    else if (g[u].size() > 1 && p == g[u][1]) {
      return dfs(g[u][0], u);
    }
    return false;
  }

  bool r = dfs(g[u][0], u);
  if (g[u].size() > 1)
    r &= dfs(g[u][1], u);
  return r;
}

bool solve() {
  if (m == 0)
    return true;
  seen.clear();

  foreach (it, g) {
    int u = it->first;
    if (!seen[u]) {
      if (!dfs(u))
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

    g.clear();
    for (int i = 0, u, v; i < m; i++) {
      cin >> u >> v;
      g[u].push_back(v);
    }

    puts(solve()? "Y" : "N");
  }

  return 0;
}
