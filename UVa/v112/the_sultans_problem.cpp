#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-6;
const double PI = acos(-1.0);

struct point {
  double x, y;
  point(double _x = 0.0, double _y = 0.0) {
    x = _x; y = _y;
  }
};

typedef vector<point> polygon;
typedef pair<point, point> line;

double ans;
int N, W, H, run;
point pivot;
vector<line> segments;

inline
int compareTo(double x, double y, double tol=1e-9) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

inline
double cross(const point& p, const point& q, const point& r) {
  return (r.x - q.x) * (p.y - q.y) - (r.y - q.y) * (p.x - q.x);
}

double angle(const point& a, const point& b, const point& c) {
  double ux = b.x - a.x, uy = b.y - a.y;
  double vx = c.x - a.x, vy = c.y - a.y;

  return acos((ux*vx + uy*vy) /
              sqrt((ux*ux + uy*uy) * (vx*vx + vy*vy)));
}

bool in_polygon(const point& p, const polygon& P) {
  if(P.size() == 0) return false;

  double sum = 0;
  for(int i = 0; i < P.size()-1; i++) {
    if(cross(p, P[i], P[i+1]) < 0)
      sum -= angle(p, P[i], P[i+1]);
    else
      sum += angle(p, P[i], P[i+1]);
  }

  return (fabs(sum - 2*PI) < EPS || fabs(sum + 2*PI) < EPS);
}

double area(const polygon& P) {
  double result = 0.0, x1, y1, x2, y2;
  for(int i = 0; i < P.size()-1; i++) {
    x1 = P[i].x; x2 = P[i+1].x;
    y1 = P[i].y; y2 = P[i+1].y;

    result += (x1 * y2 - x2 * y1);
  }

  return fabs(result) * 0.5;
}

point line_intersect_seg(const point& p, const point& q, const point& A, const point& B) {
  double a = B.y - A.y;
  double b = A.x - B.x;
  double c = B.x * A.y - A.x * B.y;
  double u = fabs(a * p.x + b * p.y + c);
  double v = fabs(a * q.x + b * q.y + c);

  return point((p.x * v + q.x * u) / (u + v),
               (p.y * v + q.y * u) / (u + v));
}

polygon cut_polygon(const point& a, const point& b, const polygon& Q) {
  polygon P;

  for(int i = 0; i < Q.size(); i++) {
    double left1 = cross(a, b, Q[i]);
    double left2 = 0.0;

    if(i != Q.size() - 1)
      left2 = cross(a, b, Q[i+1]);

    if(left1 > -EPS)
      P.push_back(Q[i]);

    if(left1 * left2 < -EPS)
      P.push_back(line_intersect_seg(Q[i], Q[i+1], a, b));
  }

  if(P.empty())
    return P;

  if(fabs(P.back().x - P.front().x) > EPS ||
     fabs(P.back().y - P.front().y) > EPS) {
    P.push_back(P.front());
  }

  return P;
}

void dfs(int i, const polygon& P) {
  if(i == N) {
    if(in_polygon(pivot, P)) {
      ans = area(P);
    }
    return;
  }

  polygon Q;
  if(cross(segments[i].first, segments[i].second, pivot) > 0) // counter-clockwise, left turn
    Q = cut_polygon(segments[i].first, segments[i].second, P);
  else
    Q = cut_polygon(segments[i].second, segments[i].first, P);
  dfs(i+1, Q);
}

polygon init() {
  polygon P;
  P.push_back(point(0, 0));
  P.push_back(point(W, 0));
  P.push_back(point(W, H));
  P.push_back(point(0, H));
  P.push_back(point(0, 0));

  return P;
}

void solve() {
  segments.resize(N);
  for(int i = 0; i < N; i++)
    cin >> segments[i].first.x >> segments[i].first.y
        >> segments[i].second.x >> segments[i].second.y;

  polygon P = init();
  dfs(0, P);

  printf("Case #%d: %.3lf\n", run++, ans);
}

int main() {
  ios_base::sync_with_stdio(false);
  run = 1;

  while(cin >> N >> W >> H >> pivot.x >> pivot.y)
    solve();

  return 0;
}
