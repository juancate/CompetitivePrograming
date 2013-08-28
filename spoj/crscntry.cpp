#include <bits/stdc++.h>

using namespace std;

int n, m, dp[2010][2010], a[2010], b[2010];

int LCS() {
  for (int i = 0; i < n; i++)
    dp[i][0] = 0;
  for (int i = 0; i < m; i++)
    dp[0][i] = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i] == b[j])
        dp[i+1][j+1] = dp[i][j]+1;
      else
        dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
    }
  }

  return dp[n][m];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    int x;
    n = 0;
    while (cin >> x) {
      if (x == 0) break;
      a[n++] = x;
    }

    int best = -int(1e9);
    while (true) {
      m = 0;
      cin >> x;
      if (x == 0) break;
      while (true) {
        if (x == 0) break;
        b[m++] = x;
        cin >> x;
      }
      best = max(best, LCS());
    }

    cout << best << '\n';
  }

  return 0;
}
