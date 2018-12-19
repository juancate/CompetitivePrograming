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

inline
int compareTo(double x, double y, double tol=1e-9) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int L, C, K;

vector<point> init() {
  vector<point> P;
  P.push_back(point(0, 0));
  P.push_back(point(L, 0));
  P.push_back(point(L, L));
  P.push_back(point(0, L));
  P.push_back(point(0, 0));

  return P;
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

bool in_polygon(const point& p, const vector<point>& P) {
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

double area(const vector<point>& P) {
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

bool on_polygon(const point& p, const vector<point>& P) {
  point inf(1000.458, 4521);
  for(int i = 0; i < P.size()-1; i++) {
    point inter = line_intersect_seg(p, inf, P[i], P[i+1]);
    if(compareTo(p.x, inter.x) == 0 && compareTo(p.y, inter.y) == 0)
      return true;
  }
  return false;
}

vector<point> cut_polygon(const point& a, const point& b, const vector<point>& Q) {
  vector<point> P;

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

void solve() {
  vector<point> cookies(C);
  vector<bool> seen(C);
  for(int i = 0; i < C; i++)
    cin >> cookies[i].x >> cookies[i].y;

  vector< vector<point> > polys;
  polys.push_back(init());

  for(int i = 0; i < K; i++) {
    point a, b;
    cin >> a.x >> a.y >> b.x >> b.y;

    vector< vector<point> > curr;

    for(int j = 0; j < polys.size(); j++) {
      vector<point> Q = cut_polygon(a, b, polys[j]);
      if(Q.size() > 1) {
        curr.push_back(Q);
        Q = cut_polygon(b, a, polys[j]);
        if(Q.size() > 1)
          curr.push_back(Q);
      }
      else {
        curr.push_back(polys[j]);
      }
    }

    polys = curr;
  }

  double ans = -1;
  for(int i = 0; i < polys.size(); i++) {
    int cnt = 0;
    double a = area(polys[i]);
    for(int j = 0; j < C; j++) if(!seen[j]) {
      if(in_polygon(cookies[j], polys[i]) && !on_polygon(cookies[j], polys[i])) {
        cnt++;
        seen[j] = true;
      }
    }
    ans = max(ans, cnt/a);
  }

  printf("%.03f\n", ans);
}

int main() {
  ios_base::sync_with_stdio(false);

  while(cin >> L >> C >> K) {
    if((L|C|K) == 0)
      break;
    solve();
  }

  return 0;
}
