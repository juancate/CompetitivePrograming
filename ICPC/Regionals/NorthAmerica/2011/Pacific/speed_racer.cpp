#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

double a, b, c, d, m, t;

double f(double v) {
  double fuel = a*v*v*v + b*v*v + c*v + d;

  return m * fuel;
}

double search() {
  double low = 0, hi = 1000;

  for (int run = 0; run < 100; run++) {
    double mid = (hi + low) / 2.0;
    double curr = f(mid);

    if (curr > t) hi = mid;
    else low = mid;
  }

  return low;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> a >> b >> c >> d >> m >> t)
    printf("%.2lf\n", floor(100*search()) / 100);

  return 0;
}
