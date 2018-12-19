#include <bits/stdc++.h>

using namespace std;

int n;
long long dp[40][40][2][2];
string num;

inline string tostr(long long x) {
  stringstream ss;
  ss << x;
  return ss.str();
}

long long solve(int index, int h, int tope, int leading) {
  if (index == n)
    return !leading? h : 0;
  if (dp[index][h][tope][leading] != -1)
    return dp[index][h][tope][leading];

  int limit = (tope)? num[index]-'0' : 9;
  long long ans = 0;

  for (int i = 0; i <= limit; i++) {
    //ans += (i == 0 && !leading);
    ans += solve(index+1, h + (i==0 && !leading), (i == limit) && tope, (i == 0) && leading);
  }

  return dp[index][h][tope][leading] = ans;
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
    long long f = a == 0? -1 : solve(0,0,1,1);

    num = tostr(b);
    n = num.size();
    memset(dp, -1, sizeof(dp));
    long long s = b == 0? -1 : solve(0,0,1,1);
    cout << (s - f) << '\n';
  }

  return 0;
}
