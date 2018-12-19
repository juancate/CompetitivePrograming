#include <bits/stdc++.h>

using namespace std;

const int maxn = 1010;

int n, a[maxn][maxn], dp[maxn][maxn];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> n) {
    if (n == 0)
      break;

    memset(a, 0, sizeof(a));
    for (int k = 1; k <= n; k++) {
      for (int j = 0, i = k-1, v; j < k; j++, i--) {
        cin >> v;
        a[i][j] = v;
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++)
        cerr << a[i][j] << ' ';
      cerr << '\n';
    }

    memset(dp, 0, sizeof(dp));
    dp[0][0] = a[0][0];
    for (int i = 1; i < n; i++)
      dp[0][i] = a[0][i] + dp[0][i-1];
    for (int i = 1; i < n; i++)
      dp[i][0] = a[i][0] + dp[i-1][0];

    for (int i = 1; i < n; i++) {
      for (int j = 1; j < n; j++)
        dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
    }

    cerr << "======================\n";
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++)
        cerr << dp[i][j] << ' ';
      cerr << '\n';
    }

    int ans = 0;
    for (int i = n-1, j = 0; j < n; i--, j++)
      ans = max(ans, dp[i][j]);
    cout << ans << '\n';
  }

  return 0;
}
