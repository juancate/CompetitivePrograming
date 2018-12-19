#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

vector<int> g[N];
int n, degree[N], cnt_sons[N];
bool orig[N][N], curr[N][N];

int calc_sons(int u, int p = -1) {
  int r;
  for (int v : g[u]) {
    if (v != p)
      r += 1 + calc_sons(v, u);
  }
  return cnt_sons[u] = r;
}

int solve(int u) {
  for (int v : g[u])
    if (curr[u][v])
      degree[u]++;

  if (degree[u] == 0 || degree[u] == 2)
    return 0;

  int r = 0;
  if (degree[u] == 1) {
    for (int v : g[u])
      if (curr[u][v]) {
        degree[v]--;
        curr[u][v] = curr[v][u] = 0;
        solve(v);
        r += 1 + cnt_sons[v];
      }
  }
  else {
    vector<int> sons;
    for (int v : g[u])
      if (curr[u][v]) {
        degree[v]--;
        curr[u][v] = curr[v][u] = 0;
        sons.push_back(solve(v) + 1);
      }
    sort(sons.rbegin(), sons.rend());
    int pos = 0;
    while (degree[u] > 2) {
      r += sons[pos++];
    }
  }

  return r;
}

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  for (int tc = 1; tc <= t; tc++) {
    memset(orig, 0, sizeof orig);

    cin >> n;
    for (int i = 0; i < n; i++)
      g[i].clear();

    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      orig[u][v] = orig[v][u] = 1;
      g[u].push_back(v);
      g[v].push_back(u);
    }

    int ans = int(1e9);
    for (int root = 0; root < n; root++) {
      memset(degree, 0, sizeof degree);
      memcpy(curr, orig, sizeof orig);

      calc_sons(root);
      int c = solve(root);
      cerr << "c: " << c << '\n';
      ans = min(ans, c);
    }

    cout << "Case #" << tc << ": " << ans << '\n';
  }

  return 0;
}
