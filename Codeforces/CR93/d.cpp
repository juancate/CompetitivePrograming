#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000010;

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
      if (z[k] < R-i+1) z[i] = z[k];
      else {
        L = i;
        while (R < n && s[R-L] == s[R]) R++;
        z[i] = R-L;
        R--;
      }
    }
  }
}

// Find best pattern which is suffix, prefix and it's inside too.
void solve() {
  int best = 0, ans = 0;
  for (int i = 1; i < n; i++) {
    if (z[i] == n-i && best >= n-i) {
      ans = n-i;
      break;
    }
    best = max(best, z[i]);
  }
  if (ans == 0)
    cout << "Just a legend\n";
  else
    cout << s.substr(0, ans) << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> s;
  n = s.size();

  calculate_z();
  solve();

  return 0;
}
