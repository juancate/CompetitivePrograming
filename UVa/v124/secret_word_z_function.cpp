#include <bits/stdc++.h>

using namespace std;

const int maxn = 2000010;

string s;
int n, N, M, z[maxn];

void calculate_z() {
  int L = 0, R = 0;
  for (int i = N+1; i < n; i++) {
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    string a, b;
    cin >> b;
    a = b;
    N = M = a.size();
    reverse(b.begin(), b.end());

    s = a + '$' + b;
    n = s.size();

    calculate_z();
    int best = 0;
    for (int i = N+1; i < n; i++)
      best = max(best, z[i]);

    string ans = a.substr(0, best);
    reverse(ans.begin(), ans.end());

    cout << ans << '\n';
  }

  return 0;
}
