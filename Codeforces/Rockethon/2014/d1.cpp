#include <bits/stdc++.h>

using namespace std;

const int INF = int(1e9);
const int N = 1000;

int vxs[N], vys[N], vxe[N], vye[N];
int hxs[N], hys[N], hxe[N], hye[N];

int calc_dist(int x1, int y1, int x2, int y2) {
  return abs(x1-x2) + abs(y1-y2);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  for (int i = 0, l; i < n; i++) {
    cin >> vxs[i] >> vys[i] >> l;
    vye[i] = vys[i] + l;
    vxe[i] = vxs[i];
  }
  for (int i = 0, l; i < m; i++) {
    cin >> hxs[i] >> hys[i] >> l;
    hxe[i] = hxs[i] + l;
    hye[i] = hys[i];
  }

  int best = -INF;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (vys[i] <= hys[j] && hys[j] <= vye[i]) {
        if (hxs[j] <= vxs[i] && vxs[i] <= hxe[j]) {
          int cx = vxs[i], cy = hys[j];
          int dist = min(min(calc_dist(cx, cy, vxs[i], vys[i]),
                             calc_dist(cx, cy, vxe[i], vye[i])),
                         min(calc_dist(cx, cy, hxs[j], hys[j]),
                             calc_dist(cx, cy, hxe[j], hye[j])));
          best = max(best, dist);
        }
      }
    }
  }

  cout << (best == -INF? 0 : best) << '\n';

  return 0;
}
