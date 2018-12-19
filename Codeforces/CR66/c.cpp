#include <bits/stdc++.h>

using namespace std;

int n;
string s;
int score[30][30], dp[111][30][111];

int solve(int index, int prev, int times) {
  if (index == n)
    return 0;

  int& ans = dp[index][prev][times];

  if (ans == -1) {
    ans = -int(1e9);

    if (times == 0) {
      ans = solve(index+1, s[index]-'a', times);
      if (index > 0)
        ans += score[prev][s[index]-'a'];
    }
    else {
      for (int i = 0; i < 26; i++) {
        int curr = solve(index+1, i, times - (i != s[index]-'a'));
        if (index > 0)
          curr += score[prev][i];
        ans = max(ans, curr);
      }
    }
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int m, k;
  memset(score, 0, sizeof(score));
  cin >> s >> k >> m;

  n = s.size();

  for (int i = 0; i < m; i++) {
    char a, b;
    int p;
    cin >> a >> b >> p;
    score[a-'a'][b-'a'] = p;
  }
  memset(dp, -1, sizeof(dp));
  cout << solve(0, 0, k) << '\n';

  return 0;
}
