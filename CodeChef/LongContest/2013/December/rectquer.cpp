#include <bits/stdc++.h>

using namespace std;

const int N = 310;

int n, a[N][N], dp[N][N][11];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      cin >> a[i][j];

  dp[1][1][a[1][1]] = 1;

  for (int i = 2; i <= n; i++) { // row
    for (int j = 1; j <= 10; j++)
      dp[i][1][j] = dp[i-1][1][j];
    dp[i][1][a[i][1]]++;
  }

  for (int i = 2; i <= n; i++) { // col
    for (int j = 1; j <= 10; j++)
      dp[1][i][j] = dp[1][i-1][j];
    dp[1][i][a[1][i]]++;
  }

  for (int i = 2; i <= n; i++) {
    for (int j = 2; j <= n; j++) {
      for (int k = 1; k <= 10; k++)
        dp[i][j][k] = dp[i-1][j][k] + dp[i][j-1][k] - dp[i-1][j-1][k];
      dp[i][j][a[i][j]]++;
    }
  }

  int Q;
  cin >> Q;

  while (Q--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int ans = 10;
    for (int k = 1; k <= 10; k++) {
      int curr = dp[x2][y2][k] - dp[x2][y1-1][k] - dp[x1-1][y2][k];
      curr += dp[x1-1][y1-1][k];

      if (curr == 0)
        ans--;
    }

    cout << ans << '\n';
  }

  return 0;
}
