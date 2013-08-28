#include <bits/stdc++.h>

using namespace std;

bool solve(int n, int m, int x1, int y1, int x2, int y2, int p, int q) {
  if (p == 0 || q == 0) { // if parallel => true
    int d = p * (y2-y1) - q * (x2-x1);
    return d == 0;
  }

  // scale
  x1 *= abs(q), x2 *= abs(q), m *= abs(q);
  y1 *= abs(p), y2 *= abs(p), n *= abs(p);
  // normalize
  p /= abs(p);
  q /= abs(q);

  int d1 = p * (y2-y1) - q * (x2-x1);
  int d2 = p * (2*n-y2-y1) - q * (x2-x1);
  int d3 = p * (y2-y1) - q * (2*m-x2-x1);
  int d4 = p * (2*n-y2-y1) - q * (2*m-x2-x1);

  int g = __gcd(2*n*q, 2*m*q);

  return (d1 % g == 0) || (d2 % g == 0) || (d3 % g == 0) || (d4 % g == 0);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, x1, y1, x2, y2, p, q;
  while (cin >> m >> n >> x1 >> y1 >> x2 >> y2 >> p >> q) {
    if ((m|n|x1|y1|x2|y2|p|q) == 0)
      break;
    if (solve(n, m, x1, y1, x2, y2, p, q))
      cout << "HIT\n";
    else
      cout << "MISS\n";
  }

  return 0;
}
