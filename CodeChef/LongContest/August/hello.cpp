#include <bits/stdc++.h>

using namespace std;

inline
int compareTo(double x, double y, double tol=1e-9) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

long long lcm(long long a, long long b) {
  return (a * b) / __gcd(a,b);
}

int n;
long long b, m[111],a[111];
double v, p[111];

int main() {
  int t;
  scanf("%d", &t);

  while (t--) {
    int x, y;
    scanf("%lf %lld %d", &v, &b, &n);

    long long total_months = 1;
    for (int i = 0; i < n; i++) {
      scanf("%lld %lf %lld", m+i, p+i, a+i);
      total_months = lcm(total_months, m[i]);
    }

    double best = total_months * v * b;
    int ans = 0;

    for (int i = 0; i < n; i++) {
      long long periods = total_months / m[i];
      double curr = periods * (m[i] * p[i] * b + a[i]);

      if (compareTo(curr, best) < 0) {
        ans = i+1;
        best = curr;
      }
    }

    printf("%d\n", ans);
  }

  return 0;
}
