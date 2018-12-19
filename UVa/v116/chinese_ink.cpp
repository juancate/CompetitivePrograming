#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
typedef pair<int,int> point;
typedef vector<point> polygon;

const double EPS = 1e-9;
const double PI = acos(-1.0);

int n, pset[44], rank[44];
polygon P[44];

void init(int n) {
  for (int i = 0; i < n; i++) {
    pset[i] = i;
    rank[i] = 0;
  }
}

int find(int x) {
  return (x == pset[x])? x : pset[x] = find(pset[x]);
}

void unite(int x, int y) {
  int px = find(x);
  int py = find(y);

  if (px == py)
    return;

  if (rank[px] < rank[py])
    pset[px] = py;
  else {
    pset[py] = px;
    if (rank[px] == rank[py])
      rank[px]++;
  }
}

int count_sets() {
  set<int> s;

  for (int i = 0; i < n; i++)
    s.insert(find(i));

  return s.size();
}

bool line_intersection(point A, point B, point C, point D, point& r) {
  double a, b, c, d, rx, ry, det, s, t;

  a = (B.x - A.x), b = (C.x - D.x);
  c = (B.y - A.y), d = (C.y - D.y);

  det = a*d - b*c;

  if (fabs(det) < EPS)
    return false;

  rx = C.x - A.x;
  ry = C.y - A.y;

  s = (rx * d - b * ry) / det;
  t = (a * ry - rx * c) / det;

  if (s < 0 || s > 1 || t < 0 || t > 1)
    return false;

  r.x = A.x + (B.x - A.x) * s;
  r.y = A.y + (B.y - A.y) * s;

  return true;
}

double angle(point a, point b, point c) {
  double ux = b.x - a.x, uy = b.y - a.y;
  double vx = c.x - a.x, vy = c.y - a.y;

  return acos((ux*vx + uy*vy) /
              sqrt((ux*ux + uy*uy) * (vx*vx + vy*vy)));
}

double cross(point p, point q, point r) {
  return (r.x - q.x) * (p.y - q.y) - (r.y - q.y) * (p.x - q.x);
}

bool in_poly(point p, polygon P) {
  if (P.size() == 0) return false;

  double sum = 0;
  for (int i = 0; i < P.size()-1; i++) {
    if (cross(p, P[i], P[i+1]) < 0)
      sum -= angle(p, P[i], P[i+1]);
    else
      sum += angle(p, P[i], P[i+1]);
  }

  return (fabs(sum - 2*PI) < EPS || fabs(sum + 2*PI) < EPS);
}

bool intersects(int i, int j) {
  const polygon& A = P[i];
  const polygon& B = P[j];
  point r;

  for (int k = 0; k < A.size()-1; k++)
    if (in_poly(A[k], B))
      return true;
  for (int l = 0; l < B.size()-1; l++)
    if (in_poly(B[l], A))
      return true;

  for (int k = 0; k < A.size()-1; k++)
    for (int l = 0; l < B.size()-1; l++)
      if (line_intersection(A[k], A[k+1], B[l], B[l+1], r))
        return true;

  return false;
}

void solve() {
  for (int i = 0, xi, yi; i < n; i++) {
    P[i].clear();
    string ln;
    getline(cin, ln);

    stringstream ss(ln);
    while (ss >> xi >> yi)
      P[i].push_back(point(xi,yi));
    P[i].push_back(P[i].front());
  }

  init(n);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < i; j++)
      if (intersects(i, j))
        unite(i, j);

  printf("%d\n", count_sets());
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> n) {
    if (n == 0)
      break;

    cin.get();
    solve();
  }

  return 0;
}
