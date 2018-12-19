#include <bits/stdc++.h>

using namespace std;

const int INF = int(1e9);

int dp[1111][22];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t, n, s;
  cin >> t;

  for (int i = 0; i <= 1000; i++)
    dp[i][0] = INF;
  for (int i = 0; i <= 20; i++)
    dp[0][i] = 0;

  for (int i = 1; i <= 1000; i++)
    for (int j = 1; j <= 20; j++)
      for (int k = 1; k <= i; k++)
        dp[i][j] = max(dp[i][j], min(dp[i-k][j]+1, dp[k][j-1]+1));

  while (t--) {
    cin >> n >> s;
    printf("%d\n", dp[n][s]);
  }

  return 0;
}
