#include <bits/stdc++.h>

using namespace std;

struct point {
  int x, y;
} p[3];

inline
int compareTo(double x, double y, double tol=1e-9) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

double sqr(double x) {
  return x*x;
}

bool is_rectangle(point a, point b, point c) {
  double aa = sqr(hypot(a.x - b.x, a.y - b.y));
  double bb = sqr(hypot(b.x - c.x, b.y - c.y));
  double cc = sqr(hypot(c.x - a.x, c.y - a.y));

  return compareTo(aa+bb, cc) == 0;
}

int a[3];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool solve() {
  sort(a, a+3);
  do {
    if (is_rectangle(p[a[0]], p[a[1]], p[a[2]]))
      return true;
  } while (next_permutation(a, a+3));
  return false;
}

bool all_distinct() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) if (i != j) {
      if (p[i].x == p[j].x && p[i].y == p[j].y)
        return false;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  for (int i = 0; i < 3; i++) {
    cin >> p[i].x >> p[i].y;
    a[i] = i;
  }

  if (solve())
    cout << "RIGHT\n";
  else {
    for (int i = 0; i < 3; i++) {
      for (int k = 0; k < 4; k++) {
        p[i].x += dx[k];
        p[i].y += dy[k];

        if (solve() && all_distinct()) {
          cout << "ALMOST\n";
          return 0;
        }
        p[i].x -= dx[k];
        p[i].y -= dy[k];
      }
    }
    cout << "NEITHER\n";
  }

  return 0;
}
