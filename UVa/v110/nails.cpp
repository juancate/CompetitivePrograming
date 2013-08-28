#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

struct point {
  long long x, y;
  point(long long _x = 0, long long _y = 0) {
    x = _x; y = _y;
  }
};

typedef vector<point> polygon;

int n;

double dist(point p1, point p2) {
  return hypot(p1.x - p2.x, p1.y - p2.y);
}

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

double perimeter(const polygon& P) {
  double sum = 0;
  int N = P.size();

  for(int i = 0; i < N-1; i++)
    sum += dist(P[i], P[i+1]);

  return sum;
}

void solve() {
  int rr;
  cin >> rr >> n;

  polygon P(n), H;

  for(int i = 0; i < n; i++)
    cin >> P[i].x >> P[i].y;

  H = monotone_chain(P);

  printf("%.5lf\n", max((double)rr, perimeter(H)));
}

int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;

  while(t--)
    solve();

  return 0;
}
