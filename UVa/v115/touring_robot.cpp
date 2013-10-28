#include <bits/stdc++.h>

using namespace std;

// Geometry : Points, Vectors

const double PI = acos(-1.0);

const int maxn = 1010;

struct point {
  double x, y;
  point(double x = 0, double y = 0) :
    x(x), y(y) { }
  point operator-(const point & p) const {
    return point(x-p.x, y-p.y);
  }
  double dot(const point & p) {
    return x * p.x + y * p.y;
  }
  double cross(const point & p) {
    return x * p.y - p.x * y;
  }
  double norm2() {
    return dot(*this);
  }
  double norm() {
    return sqrt(norm2());
  }
};

double get_angle(point p1, point p2) {
  double norm1 = p1.norm();
  double norm2 = p2.norm();

  p1.x /= norm1, p1.y /= norm1;
  p2.x /= norm2, p2.y /= norm2;

  double x = p1.dot(p2);
  double y = p1.cross(p2);

  double ang = atan2(y, x);

  if (ang < 0)
    ang += 2 * PI;

  return ang;
}

point P[maxn];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  while (cin >> N) {
    if (N == 0)
      break;

    for (int i = 0; i < N; i++)
      cin >> P[i].x >> P[i].y;
    P[N] = P[0];
    P[N+1] = P[1];

    double sum = 0;
    for (int i = 1; i <= N; i++)
      sum += get_angle(P[i] - P[i-1], P[i+1] - P[i]);
    sum /= 2 * PI;
    printf("%.0lf\n", sum);
  }

  return 0;
}
