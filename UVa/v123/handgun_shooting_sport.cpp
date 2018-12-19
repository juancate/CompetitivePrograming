#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-10;

typedef pair<double, double> segment;

const int maxn = 1010;

int n;
segment cristals[maxn];

int sign(double x) {
  return x != 0 ? (x < 0 ? -1 : 1) : 0;
}

bool cmp(segment a, segment b) {
  if (sign(a.first - b.first) != 0)
    return sign(a.first - b.first) > 0;
  return sign(a.second - b.second) > 0;
}

int calc_shots() {
  int ans = 0;

  sort(cristals, cristals+n);

  double prev = 1e200;

  for (int i = n-1; i >= 0; i--) {
    if (cristals[i].second < prev - EPS) {
      prev = cristals[i].first;
      ans++;
    }
  }

  return ans;
}

int main() {
  while (~scanf("%d", &n) && n) {
    for (int i = 0; i < n; i++) {
      int x1, y1, x2, y2;
      scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
      double t1 = atan2(y1, x1);
      double t2 = atan2(y2, x2);

      cristals[i] = segment(min(t1, t2), max(t1, t2));
    }

    printf("%d\n", calc_shots());
  }
}

