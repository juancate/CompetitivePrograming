#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int paint[N][N];

int main() {
  int n, m;
  cin >> n >> m;

  memset(paint, 0, sizeof paint);

  for (int i = 0; i < m; i++) {
    int c, u, d, l, r;
    cin >> c >> u >> d >> l >> r;
    u--, d--, l--, r--;

    for (int i = u; i <= d; i++)
      for (int j = l; j <= r; j++)
        paint[i][j] = c;
  }

  cout << "==================\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << paint[i][j] << ' ';
    cout << '\n';
  }

  return 0;
}
