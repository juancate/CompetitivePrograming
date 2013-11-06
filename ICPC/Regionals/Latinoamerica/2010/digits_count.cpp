#include <bits/stdc++.h>

using namespace std;

int n, digit;
long long dp[11][2][2], digit_sum[10];
string num;

inline string tostr(long long x) {
  stringstream ss;
  ss << x;
  return ss.str();
}

long long pot[] = { 1LL, 10LL, 100LL, 1000LL, 10000LL,
                    100000LL, 1000000LL, 10000000LL,
                    100000000LL, 1000000000LL, 10000000000LL};

int toint(int index) {
  int ret = 0;

  for (int i = index; i < n; i++)
    ret = ret*10 + num[i]-'0';

  return ret;
}

long long times(int index, int tope) {
  if (tope) return toint(index)+1;
  return pot[n-index];
}

long long solve(int index, int tope, int leading) {
  if (index == n) return 0;

  if (dp[index][tope][leading] != -1)
    return dp[index][tope][leading];

  int limit = tope? num[index]-'0' : 9;
  long long ans = 0;

  for (int i = 0; i <= limit; i++) {
    ans += solve(index+1, (i==limit) && tope, (i == 0) && leading);

    if ((i == digit && i != 0) || (i == digit && i == 0 && !leading))
      ans += times(index+1, (i==limit) && tope);
  }
  return dp[index][tope][leading] = ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b;
  while (cin >> a >> b) {
    if ((a|b) == 0)
      break;

    num = tostr(b);
    n = num.size();
    for (digit = 0; digit < 10; digit++) {
      memset(dp, -1, sizeof dp);
      digit_sum[digit] = solve(0, 1, 1);
    }

    num = tostr(a-1);
    n = num.size();
    for (digit = 0; digit < 10; digit++) {
      memset(dp, -1, sizeof dp);
      digit_sum[digit] -= solve(0, 1, 1);
    }

    cout << digit_sum[0];
    for (int i = 1; i < 10; i++)
      cout << ' ' << digit_sum[i];
    cout << '\n';
  }

  return 0;
}
