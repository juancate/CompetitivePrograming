#include <bits/stdc++.h>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int solve(int x, int y) {
  int size = 1, cnt = 0;
  int cx = 0, cy = 0, i = 0;

  if ((x == 0 || x == 1) && y == 0)
    return 0;

  while (true) {
    for (int nx = cx, ny = cy; (nx != cx+dx[i]*size) || (ny != cy+dy[i]*size);
         nx += dx[i], ny += dy[i])
    {
      if (nx == x && ny == y)
        return cnt;
    }

    cx += dx[i] * size;
    cy += dy[i] * size;

    if (cx == x && cy == y)
      return cnt;

    cnt++;

    if (i & 1)
      size++;
    i++;
    if (i > 3) i = 0;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int x, y;
  cin >> x >> y;

  cout << solve(x, y) << '\n';

  return 0;
}
