#include <bits/stdc++.h>

using namespace std;

// Digit DP

int n;
long long dp[40][40][2];
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
  if (index == n) return 1;
  if (tope) return toint(index)+1;
  return pot[n-index];
}

long long solve(int index, int tope, int leading) {
  if (index == n)
    return 0;
  if (dp[index][tope][leading] != -1)
    return dp[index][tope][leading];

  int limit = (tope)? num[index]-'0' : 9;
  long long ans = 0;

  for (int i = 0; i <= limit; i++) {
    ans += (i == 0 && !leading)? times(index+1, (i == limit) && tope) : 0;
    ans += solve(index+1, (i == limit) && tope, (i == 0) && leading);
  }

  return dp[index][tope][leading] = ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long long a, b;
  while (cin >> a >> b) {
    if (a == -1)
      break;

    num = tostr(a-1);
    n = num.size();
    memset(dp, -1, sizeof(dp));
    long long f = a == 0? -1 : solve(0,1,1);

    num = tostr(b);
    n = num.size();
    memset(dp, -1, sizeof(dp));
    long long s = b == 0? -1 : solve(0,1,1);
    cout << (s - f) << '\n';
  }

  return 0;
}
