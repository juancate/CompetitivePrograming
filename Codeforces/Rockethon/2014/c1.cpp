#include <bits/stdc++.h>

using namespace std;

const int INF = int(1e9);
const int N = 20;

int p[N], e[N], m, n;

struct obj {
  int points, pos;
  obj(int pt = 0, int p = -1) :
    points(pt), pos(p) {}

  bool operator<(const obj & o) const {
    if (points == o.points) {
      if (pos == n)
        return (m & (1 << o.pos)) != 0;
      else if (o.pos == n)
        return (m & (1 << pos)) != 0;
    }
    return points > o.points;
  }
} pc[N];

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k;
  cin >> n >> k;

  for (int i = 0; i < n; i++)
    cin >> p[i] >> e[i];

  int best = INF;
  for (int mask = 0; mask < (1 << n); mask++) {
    int curr = 0, points = 0;
    for (int i = 0; i < n; i++) {
      pc[i] = obj(p[i], i);
      if (mask & (1 << i)) {
        curr += e[i];
        points++;
      }
      else
        pc[i].points++;
    }
    pc[n] = obj(points, n);
    m = mask;
    sort(pc, pc+n+1);

    int r = 0;
    for (int i = 0; i <= n; i++)
      if (pc[i].pos == n) {
        r = i+1;
        break;
      }

    if (r <= k)
      best = min(best, curr);
  }

  cout << (best == INF? -1 : best) << '\n';

  return 0;
}
