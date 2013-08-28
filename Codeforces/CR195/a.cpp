#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int x, y;
  cin >> x >> y;

  int x1 = 0, y1 = abs(y) + abs(x);
  int x2 = abs(x) + abs(y), y2 = 0;

  if (x < 0) x2 = -x2;
  if (y < 0) y1 = -y1;

  if (x2 < x1) {
    swap(x1, x2);
    swap(y1, y2);
  }

  cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
  return 0;
}
