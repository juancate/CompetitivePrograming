#include <bits/stdc++.h>

using namespace std;

// DP

int n, k;
int memo[111][111][2];

int dp(int index, int pairs, int lastOne) {
  if (index == n)
    return (pairs == k);

  if (memo[index][pairs][lastOne] != -1)
    return memo[index][pairs][lastOne];

  int ret = 0;
  for (int i = 0; i < 2; i++)
    ret += dp(index+1, pairs + (lastOne && i == 1), i == 1);
  return memo[index][pairs][lastOne] = ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t, tc;
  cin >> t;

  while (t--) {
    cin >> tc >> n >> k;
    memset(memo, -1, sizeof(memo));
    cout << tc << ' ' << dp(0,0,0) << '\n';
  }

  return 0;
}
