#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, P1, P2, P3, T1, T2;
  cin >> n >> P1 >> P2 >> P3 >> T1 >> T2;

  int last = -1, ans = 0;
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;

    if (last < 0) last = l;

    ans += P1 * (r - l);
    if (l > last+T1) {
      if (l > last+T1+T2) {
        ans += P1 * T1;
        ans += P2 * T2;
        ans += P3 * (l - last - T2 - T1);
      }
      else {
        ans += P1 * T1;
        ans += P2 * (l - last - T1);
      }
    }
    else
      ans += P1 * (l - last);

    last = r;
  }

  cout << ans << '\n';

  return 0;
}
