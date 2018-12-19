#include <bits/stdc++.h>

using namespace std;

const int maxn = 5010;

string s;
int n, z[maxn];

void calculate_z() {
  int L = 0, R = 0;
  for (int i = 1; i < n; i++) {
    if (i > R) {
      L = R = i;
      while (R < n && s[R-L] == s[R]) R++;
      z[i] = R-L;
      R--;
    }
    else {
      int k = i-L;
      if (z[k] < R-i+1)
        z[i] = z[k];
      else {
        L = i;
        while (R < n && s[R-L] == s[R]) R++;
        z[i] = R-L;
        R--;
      }
    }
  }
}

int solve() {
  int ans = 0;
  int last = 5;
  for (int i = 5; i < n; i++) {
    if (z[i] == 4) {
      int j = i + 3;
      ans += (i - last + 1) * (n - j);
      last = i+1;
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> s;
  s = "bear$" + s;
  n = s.size();

  calculate_z();

  cout << solve() << '\n';

  return 0;
}
