#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1.0);

inline double volume(int r, int h) {
  return PI*r*r*h;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);

    double ans = 0.0;
    for (int i = 0, r, h; i < n; i++) {
      scanf("%d%d", &r, &h);
      ans += volume(r,h);
    }
    printf("%.2lf\n", ans);
  }
  return 0;
}
