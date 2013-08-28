#include <bits/stdc++.h>

using namespace std;

const int mod = int(1e9) + 7;

int a[1<<24], c[2], dp[1<<24];
long long sum[1<<24];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[1<<i];

  cin >> k;
  for (int i = 0; i < k; i++)
    cin >> c[i];

  sum[0] = 0;
  dp[0] = 1;
  for (int mask = 0; mask < 1<<n; mask++) {
    sum[mask] = sum[mask-(mask & -mask)] + a[(mask & -mask)];

    if (sum[mask] == c[0] || sum[mask] == c[1])
      continue;

    for (int i = 0; i < n; i++) {
      if (mask & (1<<i)) {
        dp[mask] = (dp[mask] + dp[mask & ~(1<<i)]);
        if (dp[mask] >= mod)
          dp[mask] -= mod;
      }
    }
  }

  cout << dp[(1<<n)-1] << '\n';

  return 0;
}
