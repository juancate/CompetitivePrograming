#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;
const int maxn = 10010;

struct point {
  long long x, y;
  int id;
} p[maxn], pivot;

double cross(point p, point q, point r) {
  return (r.x - q.x) * (p.y - q.y) - (r.y - q.y) * (p.x - q.x);
}

bool cmp(point a, point b) {
  return cross(a,b,pivot) < EPS;
}

void solve(int n) {
  for (int i = 1; i < n; i++) {
    if (p[i].y < p[0].y || (p[i].y == p[0].y && p[i].x < p[0].x))
      swap(p[0], p[i]);
  }
  pivot = p[0];
  sort(p+1, p+n, cmp);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> p[i].x >> p[i].y;
    p[i].id = i+1;
  }

  int mid = n>>1;
  solve(n);
  cout << p[0].id << ' ' << p[mid].id << '\n';

  return 0;
}
