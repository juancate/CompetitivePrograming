#include <bits/stdc++.h>

using namespace std;

string nums[3][10] = {{"._.", "...", "._.", "._.", "...", "._.", "._.", "._.", "._.", "._."},
                      {"|.|", "..|", "._|", "._|", "|_|", "|_.", "|_.", "..|", "|_|", "|_|"},
                      {"|_|", "..|", "|_.", "._|", "..|", "._|", "|_|", "..|", "|_|", "._|"}};

const int maxn = 10010;
const int INF = int(2e9);

int n, m, f[maxn], d[maxn];
pair<int,int> seg[maxn];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> n) {
    if (n == 0)
      break;

    int start = 0;
    for (int i = 0; i < n; i++) {
      cin >> d[i] >> f[i];
      int end = start + f[i] + 1;
      seg[i] = make_pair(start, end);
      start = end + 2;
    }

    cin >> m;
    while (m--) {
      int x, y;
      cin >> x >> y;
      char ans = '.';

      int i = lower_bound(seg, seg+n, make_pair(x, INF)) - seg;
      i--;

      if (seg[i].first <= x && x <= seg[i].second) {
        int posx, posy;
        if (x == seg[i].first) posx = 0;
        else if (x == seg[i].second) posx = 2;
        else posx = 1;

        if (y == 2*f[i]) posy = 0;
        else if (y < f[i]) posy = 2;
        else posy = 1;

        if (y > f[i] && y < 2*f[i] && posx == 1)
          ans = '.';
        else if (y > 0 && y < f[i] && posx == 1)
          ans = '.';
        else if (y > 2*f[i])
          ans = '.';
        else
          ans = nums[posy][d[i]][posx];
      }

      cout << ans << '\n';
    }
  }

  return 0;
}
