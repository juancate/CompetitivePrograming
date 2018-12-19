#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t, m, k;
  cin >> t;

  for (int tc = 1; tc <= t; tc++) {
    cin >> m >> k;
    double p = 1. / (k + m*k + 1);
    printf("Case #%d: %.8lf\n", tc, p);
  }

  return 0;
}
