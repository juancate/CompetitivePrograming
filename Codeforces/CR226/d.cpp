#include <bits/stdc++.h>

using namespace std;

const int N = 22;

const double EPS = 1e-9;
const double PI = acos(-1.0);

int n, l, r, x[N], y[N], a[N];
double dp[1 << N];

inline double torad(int degree) {
  return degree * PI / 180.0;
}

double calculate_right(double d, int i) {
  double theta = atan2(d - x[i], y[i]) + torad(a[i]);

  if (theta > PI / 2 - EPS)
    return r;

  return x[i] + tan(theta) * y[i];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cout.precision(10);
  cout.setf(ios::fixed);

  cin >> n >> l >> r;
  for (int i = 0; i < n; i++)
    cin >> x[i] >> y[i] >> a[i];

  for (int i = 0; i < (1 << n); i++)
    dp[i] = -100000000;

  dp[0] = l;
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < n; j++) {
      if ((i & (1 << j)) == 0)
        dp[i | (1 << j)] = max(dp[i | (1 << j)], calculate_right(dp[i], j));
    }
  }

  cout << min(dp[(1<<n)-1]-l, double(r-l)) << '\n';

  return 0;
}
