#include <bits/stdc++.h>

using namespace std;

const int INF = int(1e9);

int n, dp[111][111], sum[111];

int kadane() {
  int max_sum = -INF;
  int curr_sum = 0;

  for (int j = 0; j < n; j++) {
    curr_sum = max(sum[j], curr_sum + sum[j]);
    max_sum = max(max_sum, curr_sum);
  }

  return max_sum;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> dp[i][j];

  int ans = -INF;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      sum[j] = 0;

    for (int j = i; j < n; j++) {
      for (int k = 0; k < n; k++)
        sum[k] += dp[j][k];
      ans = max(ans, kadane());
    }
  }

  cout << ans << '\n';

  return 0;
}
