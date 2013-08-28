#include <bits/stdc++.h>

using namespace std;

const long long p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

int n;
unsigned long long dp[1111][11];

unsigned long long fpow(long long a, long long b) {
  unsigned long long x = 1LL;

  while (b > 0) {
    if (b & 1) x = x * a;
    a = a * a;
    b >>= 1;
  }

  return x;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;

  for (int i = 0; i < n; i++) {
    dp[i][0] = fpow(p[0], i);
    for (int j = 1; j < 11; j++) {
      dp[i][j] = int(2e18);
      for (int k = 0; k < i; k++)
        if (i % (k + 1) == 0)
          dp[i][j] = min(dp[i][j], dp[i / (k+1)][j-1] * fpow(p[j], k));
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 11; j++)
      cerr << dp[i][j] << ' ';
    cerr << '\n';
  }

  unsigned long long best = int(2e18);
  for (int i = 0; i < 11; i++)
    best = min(best, dp[n-1][i]);
  cout << best << '\n';

  return 0;
}
