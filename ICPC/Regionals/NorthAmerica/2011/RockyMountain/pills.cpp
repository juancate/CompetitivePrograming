#include <bits/stdc++.h>

using namespace std;

long long memo[66][2]; // dp[days][cant], cant => half or full

long long dp(int p, int c) {
  if (p == 0)
    return 1LL;

  if (memo[p][c] != -1)
    return memo[p][c];

  memo[p][c] = 0;
  for (int i = 0; i < 2; i++)
    memo[p][c] += dp(p-1, i);

  return memo[p][c];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(memo, -1, sizeof(memo));
  for (int i = 2; i <= 60; i+=2)
    dp(i,0);

  int n;
  while (cin >> n) {
    if (n == 0)
      break;
    cout << dp(n, 0) << '\n';
  }

  return 0;
}
