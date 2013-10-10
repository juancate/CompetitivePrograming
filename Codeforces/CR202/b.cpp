#include <bits/stdc++.h>

using namespace std;

int v, a[10];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> v;
  int m = int(1e9);
  for (int i = 1; i <= 9; i++) {
    cin >> a[i];
    m = min(m, a[i]);
  }

  if (v < m) {
    cout << -1 << '\n';
    return 0;
  }

  int cnt = v / m;
  int use = cnt * m;

  for (int i = 9; i > 0; i--) {
    while (v - a[i] + m >= use && cnt > 0) {
      v -= a[i];
      use -= m;
      cnt--;
      cout << i;
    }
  }
  cout << '\n';

  return 0;
}
