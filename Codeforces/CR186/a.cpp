#include <bits/stdc++.h>

using namespace std;

int n, m, a[111];
bool g[111][111];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v;
    g[u][v] = g[v][u] = 1;
  }

  int ans = int(1e9);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= n; k++)
        if (i != j && j != k && i != k)
          if (g[i][j] && g[i][k] && g[j][k])
            ans = min(ans, a[i]+a[j]+a[k]);

  cout << (ans == int(1e9)? -1 : ans) << '\n';

  return 0;
}
