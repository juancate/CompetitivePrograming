#include <bits/stdc++.h>

using namespace std;

// WA!!!

const int maxn = 111;

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

int solve() {
  int ans = int(1e9);
  for (int i = 1; i < n; i++) {
    if (z[i] > 0) {
      bool valid = true;
      int sum = 0;
      for (int j = i; j >= 0; j -= z[i]) {
        if (z[j] != z[i]+sum) {
          valid = false;
          break;
        }
        sum += z[i];
      }
      sum = z[i];
      for (int j = i + z[i]; j < n; j += z[i]) {
        if (z[j] != z[i]-sum && (z[i] > 0 && sum > 0)) {
          valid = false;
          break;
        }
        sum -= z[i];
      }

      if (valid)
        ans = min(ans, z[i]);
    }
  }
  if (ans == int(1e9))
    ans = 0;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    cin >> s;

    n = s.size();
    memset(z, 0, sizeof z);

    calculate_z();
    cerr << "z => ";
    for (int i = 0; i < n; i++)
      cerr << z[i] << ' ';
    cerr << '\n';

    cout << solve() << '\n';
    if (t)
      cout << '\n';
  }

  return 0;
}
