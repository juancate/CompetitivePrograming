#include <bits/stdc++.h>

using namespace std;

inline
int compareTo(double x, double y, double tol=1e-9) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

double get_time(double curr, double freq, double target) {
  double t = (target - curr) / freq;

  return t;
}

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cout.precision(7);
  cout.setf(ios::fixed);

  int t;
  cin >> t;

  for (int tc = 1; tc <= t; tc++) {
    double C, F, X;
    cin >> C >> F >> X;

    double curr = 0.0, ans = 0.0, freq = 2.0;

    while (compareTo(curr, X) < 0) {
      if (compareTo(curr, C) >= 0) {
        double a = ans + get_time(curr, freq, X);
        double b = ans + get_time(curr-C, freq+F, X);

        if (compareTo(b, a) < 0) {
          curr -= C;
          freq += F;
        }
        else {
          ans += get_time(curr, freq, X);
          curr = X;
        }
      }
      else {
        double d1 = (C - curr);
        double d2 = (X - curr);

        if (compareTo(d1, d2) <= 0) {
          ans += (C - curr) / freq;
          curr += (C - curr);
        }
        else {
          ans += (X - curr) / freq;
          curr += (X - curr);
        }
      }
    }

    cout << "Case #" << tc << ": ";
    cout << ans << '\n';
  }

  return 0;
}
