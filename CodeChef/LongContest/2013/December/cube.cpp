#include <bits/stdc++.h>

using namespace std;

string A, B;
int n, p, dp[44][44][44];

inline
int sum(int i, int j, int k) {
  int s = 0;
  s = dp[i+1][j][k] + dp[i][j+1][k] + dp[i][j][k+1] + dp[i+1][j+1][k+1];
  s -= dp[i+1][j+1][k] + dp[i][j+1][k+1] + dp[i+1][j][k+1];

  return s + (A[i*n*n + j*n + k] == B[i*n*n + j*n + k]);
}

inline
int get_cube(int i, int j, int k, int sz) {
  int s = dp[i][j][k];
  s = s - dp[i+sz][j][k] - dp[i][j+sz][k] - dp[i][j][k+sz] - dp[i+sz][j+sz][k+sz];
  s += dp[i][j+sz][k+sz] + dp[i+sz][j+sz][k] + dp[i+sz][j][k+sz];

  return s;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    cin >> n >> p >> A >> B;

    if (p == 0) {
      cout << n << ' ' << 1 << '\n';
      continue;
    }

    memset(dp, 0, sizeof dp);
    for (int i = n-1; i >= 0; i--)
      for (int j = n-1; j >= 0; j--)
        for (int k = n-1; k >= 0; k--)
          dp[i][j][k] = sum(i, j, k);

    int ans = -1, cnt = 0;

    for (int sz = n; sz > 0; sz--) {
      int curr = 0;
      int total = sz * sz * sz;
      for (int i = 0; i + sz - 1 < n; i++)
        for (int j = 0; j + sz - 1 < n; j++)
          for (int k = 0; k + sz - 1 < n; k++)
            if (get_cube(i,j,k,sz) * 100 >= p * total)
              curr++;

      if (curr > 0) {
        ans = sz;
        cnt = curr;
        break;
      }
    }

    cout << ans;
    if (ans > 0) cout << ' ' << cnt;
    cout << '\n';
  }

  return 0;
}
