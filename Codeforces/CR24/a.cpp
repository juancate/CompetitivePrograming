#include <bits/stdc++.h>

using namespace std;

const int maxn = 111;

int n, c[maxn][maxn];
bool g1[maxn][maxn], g2[maxn][maxn];

int dfs(int u, int p = -1) {
  if (u == 1 && p != -1)
    return 0;

  int ans = int(1e9);
  for (int v = 1; v <= n; v++) {
    if (v == p) continue;
    int curr = 0;
    if (g2[u][v]) {
      if (!g1[u][v])
        curr += c[u][v];
      curr += dfs(v, u);
      ans = min(curr, ans);
    }
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;

  int sum = 0;
  for (int i = 0; i < n; i++) {
    int a, b, ci;
    cin >> a >> b >> ci;
    g1[a][b] = 1;
    g2[a][b] = g2[b][a] = 1;
    c[a][b] = c[b][a] = ci;
    sum += ci;
  }

  int best = dfs(1);
  best = min(best, sum - best);
  cout << best << '\n';

  return 0;
}
