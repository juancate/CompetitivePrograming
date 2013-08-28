#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, a, b, c;
  cin >> n >> a >> b >> c;

  int ans = 0;
  for (int i = 0; i <= a; i++) {
    for (int j = 0; j <= b; j++) {
      int k = (n - .5 * i - j) / 2;

      if (k < 0 || k > c) continue;
      if ((.5*i + j + 2*k) == n)
        ans++;
    }
  }
  cout << ans << '\n';

  return 0;
}
