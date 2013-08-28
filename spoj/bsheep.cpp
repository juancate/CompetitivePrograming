#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
typedef pair<long long, long long> point;
typedef vector<point> polygon;

const double EPS = 1e-9;

double dist(point p1, point p2) {
  return hypot(p1.x - p2.x, p1.y - p2.y);
}

double cross(point p, point q, point r) {
  return (r.x - q.x) * (p.y - q.y) - (r.y - q.y) * (p.x - q.x);
}

bool collinear(point p, point q, point r) {
  return fabs(cross(p, q, r)) < EPS;
}

bool ccw(point p, point q, point r) {
  return cross(p, q, r) > 0;
}

bool cmp(point a, point b) {
  if (a.y == b.y)
    return a.x < b.x;
  return a.y < b.y;
}

polygon monotone_chain(polygon P) {
  int N = P.size();

  if (N < 3) {
    P.push_back(P[0]);
    return P;
  }

  polygon H(2*N);
  sort(P.begin(), P.end(), cmp);

  int k, start;

  k = start = 0;

  for (int i = 0; i < N; i++) {
    while (k-start >= 2 && !ccw(H[k-2], H[k-1], P[i]))
      k--;

    H[k++] = P[i];
  }

  k--;
  start = k;
  for (int i = N-1; i >= 0; i--) {
    while (k-start >= 2 && !ccw(H[k-2], H[k-1], P[i]))
      k--;
    H[k++] = P[i];
  }

  H.resize(k);

  return H;
}

double perimeter(const polygon& P) {
  double r = 0.0;

  for (int i = 0; i < P.size()-1; i++)
    r += dist(P[i], P[i+1]);

  return r;
}

void solve() {
  int n;
  cin >> n;

  polygon P(n);
  map<point, int> m;
  for (int i = 0; i < n; i++) {
    cin >> P[i].x >> P[i].y;
    if (!m.count(P[i]))
      m[P[i]] = i+1;
  }

  polygon H = monotone_chain(P);
  double per = perimeter(H);

  printf("%.2lf\n", per);
  for (int i = 0; i < H.size()-1; i++) {
    if (i) printf(" ");
    printf("%d", m[H[i]]);
  }
  printf("\n");
}

int main() {
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;

  while (t--) {
    solve();
    if (t > 0)
      printf("\n");
  }

  return 0;
}
