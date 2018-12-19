#include <bits/stdc++.h>

using namespace std;

long long memo[66][66][2];

int n;
string num;

string tobin(long long x) {
  string t;
  while (x > 0) {
    t.push_back('0' + (x & 1));
    x >>= 1;
  }
  reverse(t.begin(), t.end());
  return t;
}

long long dp(int index, int ones, int top) {
  if (index == n)
    return ones;

  if (memo[index][ones][top] == -1) {
    long long ans = 0;

    int limit = top? num[index]-'0' : 1;

    for (int i = 0; i <= limit; i++)
      ans += dp(index+1, ones + (i == 1), (i == limit) && top);

    memo[index][ones][top] = ans;
  }
  return memo[index][ones][top];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long long A, B;

  while (cin >> A >> B) {
    num = tobin(B);
    n = num.size();
    memset(memo, -1, sizeof memo);
    long long ans = dp(0,0,1);

    num = tobin(A-1);
    n = num.size();
    memset(memo, -1, sizeof memo);
    ans -= dp(0,0,1);

    cout << ans << '\n';
  }

  return 0;
}
