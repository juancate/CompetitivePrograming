#include <bits/stdc++.h>

using namespace std;

double arc;
long long m, R;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> m >> R;
  arc = R*sqrt(2.);

  double ans = 0;

  for (int i = 1; i <= m; i++) {
    ans += 2.*R;

    if (i-1 > 0) ans += arc + 2.*R;
    if (i+1 <= m) ans += arc + 2.*R;

    long long nl = i-2;
    long long nr = m-i-1;

    if (nl > 0) ans += R*nl*nl + R*nl + 2.*nl*arc;
    if (nr > 0) ans += R*nr*nr + R*nr + 2.*nr*arc;
  }

  ans = ans / m / m;

  cout.precision(10);
  cout.setf(ios::fixed);
  cout << ans << '\n';

  return 0;
}
