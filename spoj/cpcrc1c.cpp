#include <bits/stdc++.h>

using namespace std;

// http://www.spoj.com/problems/CPCRC1C/
// DP

int n;
string num;

long long memo[12][2];

long long pot[] = {1LL, 10LL, 100LL, 1000LL, 10000LL, 100000LL, 1000000LL,
                   10000000LL, 100000000LL, 1000000000LL, 10000000000LL};

inline string to_str(int x) {
  stringstream ss;
  ss << x;
  return ss.str();
}

int toint(int index) {
  int ret = 0;

  for (int i = index; i < n; i++)
    ret = ret*10 + num[i]-'0';

  return ret;
}

long long times(int index, int top) {
  if (top) return toint(index)+1;
  return pot[n-index];
}

long long dp(int index, int top) {
  if (index == n)
    return 0;

  if (memo[index][top] != -1)
    return memo[index][top];

  int limit = top? num[index]-'0' : 9;

  long long ans = 0;

  for (int i = 0; i <= limit; i++) {
    ans += i * times(index+1, top && (i == limit));
    ans += dp(index+1, top && (i == limit));
  }

  return memo[index][top] = ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int A, B;
  while (cin >> A >> B) {
    if (A == -1)
      break;
    string a, b;
    a = to_str(A-1);
    b = to_str(B);

    n = b.size();
    num = b;

    memset(memo, -1, sizeof memo);
    long long ans = dp(0, 1);

    n = a.size();
    num = a;
    memset(memo, -1, sizeof memo);
    ans -= dp(0, 1);

    cout << ans << '\n';
  }

  return 0;
}
