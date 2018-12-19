#include <bits/stdc++.h>

using namespace std;

inline
int compareTo(double x, double y, double tol=1e-9) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class triangle {
public:
  double sides[3];
  triangle(double a=0, double b=0, double c=0) {
    sides[0] = a; sides[1] = b; sides[2] = c;
    sort(sides, sides+3);
  }
};

bool cmp(const triangle& a, const triangle& b) {
  for (int i = 0; i < 2; i++)
    if (compareTo(a.sides[i]/b.sides[i], a.sides[i+1]/b.sides[i+1]) != 0)
      return false;
  return true;
}

vector<triangle> ans;

bool contains(const triangle& t) {
  for (int i = 0; i < ans.size(); i++)
    if (cmp(t,ans[i]))
      return true;
  return false;
}

inline
double split(double a, double b, double c) {
  return sqrt((2*b*b + 2*c*c - a*a) * .25);
}

void dfs(triangle t) {
  if (contains(t))
    return;

  ans.push_back(t);
  double m = t.sides[2] * .5;
  double d = split(t.sides[2], t.sides[1], t.sides[0]);

  triangle next(d,m,t.sides[0]);
  dfs(next);

  next = triangle(d,m,t.sides[1]);
  dfs(next);
}

void solve() {
  ans.clear();

  triangle t;
  for (int i = 0; i < 3; i++)
    cin >> t.sides[i];

  dfs(t);

  cout << ans.size() << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}
