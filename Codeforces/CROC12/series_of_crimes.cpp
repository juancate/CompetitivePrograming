#include <bits/stdc++.h>

using namespace std;

const int maxn = 111;

int n, m;
char g[maxn][maxn];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  vector<int> r, c;
  for (int i = 0; i < n; i++) {
    cin >> g[i];
    for (int j = 0; j < m; j++)
      if (g[i][j] == '*') {
        r.push_back(i);
        c.push_back(j);
      }
  }

  int left_x = maxn, right_x = -1, up_y = maxn, down_y = -1;

  for (int i = 0; i < r.size(); i++) {
    left_x = min(left_x, c[i]);
    right_x = max(right_x, c[i]);
    up_y = min(up_y, r[i]);
    down_y = max(down_y, r[i]);
  }

  vector<int> ax, ay;

  ax.push_back(left_x); ay.push_back(down_y);
  ax.push_back(left_x); ay.push_back(up_y);
  ax.push_back(right_x); ay.push_back(up_y);
  ax.push_back(right_x); ay.push_back(down_y);

  for (int i = 0; i < ax.size(); i++) {
    if (g[ay[i]][ax[i]] != '*') {
      cout << ay[i]+1 << ' ' << ax[i]+1 << '\n';
      return 0;
    }
  }

  return 0;
}
