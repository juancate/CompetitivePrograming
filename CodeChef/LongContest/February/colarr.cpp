#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n, a[N], b[N][N], c[N][N], p[N][2], memo[N][N];

int dp(int cell, int k) {
  if (cell == n)
    return 0;

  if (memo[cell][k] != -1)
    return memo[cell][k];

  int r = p[cell][0] + dp(cell+1, k);
  if (k > 0)
    r = max(r, p[cell][1] + dp(cell+1, k-1));
  return memo[cell][k] = r;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    int m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
      cin >> a[i];

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> b[i][j];

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> c[i][j];

    for (int i = 0; i < n; i++) {
      int best = b[i][a[i]-1];
      for (int j = 0; j < m; j++)
        best = max(best, b[i][j] - c[i][j]);
      p[i][0] = b[i][a[i]-1];
      p[i][1] = best;
    }

    memset(memo, -1, sizeof memo);
    cout << dp(0, k) << '\n';
  }

  return 0;
}
