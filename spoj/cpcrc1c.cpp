#include <bits/stdc++.h>

using namespace std;

// WA!!!

int n;
string num;

long long memo[12][2][2];

long long pot[] = {1LL, 10LL, 100LL, 1000LL, 10000LL, 100000LL, 1000000LL, 10000000LL, 100000000LL, 1000000000LL};

inline string to_str(int x) {
  stringstream ss;
  ss << x;
  return ss.str();
}

long long dp(int index, int top, int zero) {
  if (index == n)
    return 1;

  if (memo[index][top][zero] != -1)
    return memo[index][top][zero];

  int limit = top? num[index]-'0' : 9;

  long long ans = 0;

  for (int i = 0; i <= limit; i++) {
    if (!top && index < n-1)
      ans += i * pot[n-i-1];
    ans += i + dp(index+1, top && i == num[index], zero && i == 0);
  }

  return memo[index][top][zero] = ans;
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

    cerr << "num => " << num << '\n';
    memset(memo, -1, sizeof memo);
    long long ans = dp(0, 1, 1);
    cerr << "ans => " << ans << '\n';

    n = a.size();
    num = a;
    cerr << "num => " << num << '\n';
    memset(memo, -1, sizeof memo);
    ans -= dp(0, 1, 1);

    cout << ans << '\n';
  }

  return 0;
}
