#include <bits/stdc++.h>

using namespace std;

// DP digit
// http://www.spoj.com/problems/NY10E/

int n, num[65];
long long memo[10][65];

long long dp(int digit, int index) {
  if (index == n)
    return 1LL;
  if (memo[digit][index] != -1)
    return memo[digit][index];

  long long ans = 0;

  for (int i = digit; i <= 9; i++)
    ans += dp(i, index+1);

  return memo[digit][index] = ans;
}

int main(int argc, const char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t, tc;
  cin >> t;

  while (t--) {
    cin >> tc >> n;
    memset(memo, -1, sizeof memo);
    cout << tc << ' ' << dp(0, 0) << '\n';
  }

  return 0;
}
