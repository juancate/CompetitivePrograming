#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> point;
#define x first
#define y second

const int n = 8;

point a[n];
int p[n], s[4], f[4];

inline
int compareTo(double x, double y, double tol=1e-9) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

double sqr(double x) {
  return x*x;
}

bool is_valid(double x1, double y1, double x2, double y2,
              double x3, double y3, double x4, double y4) {
  double cx = (x1 + x2 + x3 + x4) / 4.;
  double cy = (y1 + y2 + y3 + y4) / 4.;

  double dd1 = sqr(cx - x1) + sqr(cy - y1);
  double dd2 = sqr(cx - x2) + sqr(cy - y2);
  double dd3 = sqr(cx - x3) + sqr(cy - y3);
  double dd4 = sqr(cx - x4) + sqr(cy - y4);

  return (compareTo(dd1, dd2) == 0 && compareTo(dd1, dd3) == 0 && compareTo(dd1, dd4) == 0);
}

void solve() {
  do {
    for (int i = 0; i < 4; i++)
      f[i] = p[i], s[i] = p[i+4];
    sort(f, f+4);
    sort(s, s+4);
    bool rect = false, square = false;
    do {
      if (is_valid(a[f[0]].x, a[f[0]].y, a[f[1]].x, a[f[1]].y, a[f[2]].x, a[f[2]].y, a[f[3]].x, a[f[3]].y)) {
        double d1 = sqr(a[f[0]].x - a[f[1]].x) + sqr(a[f[0]].y - a[f[1]].y);
        double d2 = sqr(a[f[1]].x - a[f[2]].x) + sqr(a[f[1]].y - a[f[2]].y);
        double d3 = sqr(a[f[2]].x - a[f[3]].x) + sqr(a[f[2]].y - a[f[3]].y);
        double d4 = sqr(a[f[3]].x - a[f[0]].x) + sqr(a[f[3]].y - a[f[0]].y);

        if (compareTo(d1,d2) == 0 && compareTo(d1, d3) == 0 && compareTo(d1, d4) == 0)
          continue;

        rect = true;
        break;
      }
    } while (next_permutation(f, f+4));

    if (!rect)
      continue;

    do {
      if (is_valid(a[s[0]].x, a[s[0]].y, a[s[1]].x, a[s[1]].y, a[s[2]].x, a[s[2]].y, a[s[3]].x, a[s[3]].y)) {
        square = true;
        break;
      }
    } while (next_permutation(s, s+4));

    if (rect && square) {
      cout << "YES\n";
      for (int i = 0; i < 4; i++)
        cout << s[i]+1 << ' ';
      cout << '\n';
      for (int i = 0; i < 4; i++)
        cout << f[i]+1 << ' ';
      cout << '\n';
      return;
    }
  } while (next_permutation(p, p+n));
  cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  for (int i = 0; i < n; i++) {
    cin >> a[i].x >> a[i].y;
    p[i] = i;
  }

  solve();

  return 0;
}
