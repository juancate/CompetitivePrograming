#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

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

void print(const polygon& P) {
  for(int i = 0; i < P.size(); i++) {
    if(i) cout << ' ';
    cout << '(' << P[i].x << ',' << P[i].y << ')';
  }
  cout << endl;
}

void solve(string ln) {
  stringstream ss(ln);
  double x, y;

  polygon P;
  while(ss >> x >> y)
    P.push_back(point(x, y));

  polygon H = monotone_chain(P);
  print(H);
}

string clean(string s) {
  int n = s.size();
  string t;

  for(int i = 0; i < n; i++) {
    if(s[i] == '(' || s[i] == ')' || s[i] == ',')
      t.push_back(' ');
    else
      t.push_back(s[i]);
  }

  return t;
}

int main() {
  ios_base::sync_with_stdio(false);

  string ln;
  while(getline(cin, ln))
    solve(clean(ln));

  return 0;
}
