#include <bits/stdc++.h>

using namespace std;

const int maxn = int(1e5);

struct point {
  long long x, y, dist;
  point(long long x=0, long long y=0) :
    x(x), y(y) {
    dist = abs(x) + abs(y);
  }

  bool operator<(const point& p) const {
    return dist < p.dist;
  }
} p[maxn];

int n;
vector<int> move, t_op;
vector<char> d;

void move_to(int x, int y) {
  if (x != 0) {
    t_op.push_back(1);
    move.push_back(abs(x));
  }

  if (x > 0)
    d.push_back('R');
  if (x < 0)
    d.push_back('L');

  if (y != 0) {
    t_op.push_back(1);
    move.push_back(abs(y));
  }

  if (y > 0)
    d.push_back('U');
  if (y < 0)
    d.push_back('D');
  t_op.push_back(2);
}

void move_from(int x, int y) {
  if (y != 0) {
    t_op.push_back(1);
    move.push_back(abs(y));
  }

  if (y > 0)
    d.push_back('D');
  if (y < 0)
    d.push_back('U');

  if (x != 0) {
    t_op.push_back(1);
    move.push_back(abs(x));
  }

  if (x > 0)
    d.push_back('L');
  if (x < 0)
    d.push_back('R');
  t_op.push_back(3);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    p[i] = point(x,y);
  }

  for (int i = 0; i < n; i++) {
    move_to(p[i].x, p[i].y);
    move_from(p[i].x, p[i].y);
  }

  cout << t_op.size() << '\n';
  int j = 0;

  for (int i = 0; i < t_op.size(); i++) {
    cout << t_op[i];
    if (t_op[i] == 1) {
      cout << ' ' << move[j] << ' ' << d[j];
      j++;
    }
    cout << '\n';
  }

  return 0;
}
