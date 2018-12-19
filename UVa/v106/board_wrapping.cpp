#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1.0);

struct point {
  double x, y;
  point(double _x = 0, double _y = 0) {
    x = _x; y = _y;
  }
};

typedef vector<point> polygon;

int n;

double cross(point p, point q, point r) {
  return (r.x - q.x) * (p.y - q.y) - (r.y - q.y) * (p.x - q.x);
}

bool ccw(point p, point q, point r) {
  return cross(p, q, r) > 0;
}

bool cmp(point a, point b) {
  if(fabs(a.x - b.x) < EPS)
    return (a.y - b.y) < 0;
  return (a.x - b.x) < 0;
}

polygon monotone_chain(polygon P) {
  int N = P.size();

  if(N <= 3) {
    P.push_back(P[0]);
    return P;
  }

  polygon H(2*N);
  sort(P.begin(), P.end(), cmp);

  int k, start;
  k = start = 0;

  for(int i = 0; i < N; i++) {
    while(k-start >= 2 && !ccw(H[k-2], H[k-1], P[i]))
      k--;
    H[k++] = P[i];
  }

  k--;
  start = k;
  for(int i = N-1; i >= 0; i--) {
    while(k-start >= 2 && !ccw(H[k-2], H[k-1], P[i]))
      k--;
    H[k++] = P[i];
  }

  H.resize(k);

  return H;
}

point rotate(point p, double theta, double x, double y) {
  double tx = p.x - x;
  double ty = p.y - y;
  double rad = theta * PI / 180.;
  return point(tx * cos(rad) - ty * sin(rad) + x,
               tx * sin(rad) + ty * cos(rad) + y);
}

polygon build_board(double x, double y, double W, double H, double theta) {
  polygon P;

  P.push_back(point(x - .5*W, y - .5*H));
  P.push_back(point(x - .5*W, y + .5*H));
  P.push_back(point(x + .5*W, y + .5*H));
  P.push_back(point(x + .5*W, y - .5*H));

  for(int i = 0; i < P.size(); i++)
    P[i] = rotate(P[i], theta, x, y);

  return P;
}

double area(const polygon& P) {
  double result = 0.0, x1, y1, x2, y2;
  for(int i = 0; i < P.size()-1; i++) {
    x1 = P[i].x; x2 = P[i+1].x;
    y1 = P[i].y; y2 = P[i+1].y;
    result += (x1 * y2 - x2 * y1);
  }

  return fabs(result) * .5;
}

void solve() {
  cin >> n;

  polygon P;
  double ans = 0.0, sum = 0.0;

  for(int i = 0; i < n; i++) {
    double x, y, W, H, theta;
    cin >> x >> y >> W >> H >> theta;

    sum += W*H;
    polygon Q = build_board(x, y, W, H, 360-theta);
    assert(Q.size() == 4);
    for(int j = 0; j < Q.size(); j++)
      P.push_back(Q[j]);
  }

  polygon H = monotone_chain(P);
  ans = sum / area(H);

  printf("%.1lf %\n", ans * 100.);
}

int main() {
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;

  while(t--) {
    solve();
  }
  return 0;
}
