#include <bits/stdc++.h>

using namespace std;

int n;
string num;
long long dp[11][2];

long long pot[] = { 1LL, 10LL, 100LL, 1000LL, 10000LL,
                    100000LL, 1000000LL, 10000000LL,
                    100000000LL, 1000000000LL, 10000000000LL};

inline string tostr(int x) {
  stringstream ss; ss << x;
  return ss.str();
}

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

long long solve(int index, int tope) {
  if (index == n) return 0;

  if (dp[index][tope] != -1)
    return dp[index][tope];

  int limit = tope? num[index]-'0' : 9;
  long long ans = 0;

  for (int i = 0; i <= limit; i++) {
    ans += solve(index+1, (i==limit) && tope);
    ans += i*times(index+1, (i==limit) && tope);
  }
  return dp[index][tope] = ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b;
  while (cin >> a >> b) {
    if ((a|b) == 0)
      break;

    num = tostr(a-1);
    n = num.size();
    memset(dp, -1, sizeof(dp));
    long long f = solve(0,1);

    num = tostr(b);
    n = num.size();
    memset(dp, -1, sizeof(dp));
    long long s = solve(0,1);

    cout << (s-f) << '\n';
  }

  return 0;
}
