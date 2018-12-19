#include <bits/stdc++.h>

using namespace std;

const int INF = (int)(1e9);
const double EPS = 1e-6;

int compareTo(double x, double y, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int maxn = 110;

struct point {
  double x, y;

  point(double a = 0, double b = 0) {
    x = a; y = b;
  }

  void print() const {
    cout << "(" << x << ", " << y << ")\n";
  }
} poly[maxn];

double cross(const point & p, const point & q, const point & r) {
  return (r.x - q.x) * (p.y - q.y) - (r.y - q.y) * (p.x - q.x);
}

double square_dist(const point & p, const point & q) {
  return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);
}

bool collinear(const point & p, const point & q, const point & r) {
  return compareTo(cross(p, q, r), 0) == 0;
}

void midPoint(const point & a, const point & b, point & c) {
  c.x = (a.x + b.x) * .5;
  c.y = (a.y + b.y) * .5;
}

bool intersect(const point & A, const point & B, const point & C, const point & D, point& center) {
  double a, b, c, d, rx, ry, det, s, x, y;
  a = (B.x - A.x); // R'
  b = (C.x - D.x); // R
  c = (B.y - A.y);
  d = (C.y - D.y);

  rx = C.x - A.x;
  ry = C.y - A.y;

  det = a*d - b*c;
  s = (rx * d - b * ry) / det;
  x = A.x + (B.x - A.x) * s;
  y = A.y + (B.y - A.y) * s;

  center = point(x, y);
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  while(cin >> n) {
    if (n == 0)
      break;

    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      poly[i] = point(x, y);
    }

    if(n <= 2) {
      cout << n << '\n';
      continue;
    }

    int ans = 0;
    point center;

    for(int i = 0; i < n; i++) {
      for(int j = i+1; j < n; j++) {
        for(int k = j+1; k < n; k++) {
          point & a = poly[i];
          point & b = poly[j];
          point & c = poly[k];

          if (collinear(a, b, c)) {
            ans = max(ans, 2);
            continue;
          }

          point p1, p2, ab, bc;
          midPoint(a, b, ab);
          midPoint(a, c, bc);

          if (a.x == b.x) {
            p1.x = ab.x - 1;
            p1.y = ab.y;
          }
          else {
            p1.x = ab.x + (a.y - b.y);
            p1.y = ab.y - (a.x - b.x);
          }

          if (a.x == c.x) {
            p2.x = bc.x - 1;
            p2.y = bc.y;
          }
          else {
            p2.x = bc.x + (a.y - c.y);
            p2.y = bc.y - (a.x - c.x);
          }

          intersect(ab, p1, bc, p2, center);
          int cnt = 0;
          double d = square_dist(a, center);

          for(int l = 0; l < n; l++)
            if(compareTo(square_dist(poly[l], center), d) == 0)
              cnt++;

          ans = max(ans, cnt);
        }
      }
    }

    cout << ans << '\n';
  }
}

