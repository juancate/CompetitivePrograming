#include <bits/stdc++.h>

using namespace std;

class state {
public:
  int x, y, z;
  state(int x = 0, int y = 0, int z = 0) {
    this->x = x; this->y = y; this->z = z;
  }
} black[256];

int n, m;
bool g[22][22][22], seen[22][22][22];

bool valid(int nx, int ny, int nz) {
  return nx >= 0 && nx <= n && ny >= 0 && ny <= n && nz >= 0 && nz <= n && (nx+ny+nz) == n;
}

bool bfs() {
  bool x, y, z;
  memset(seen, 0, sizeof(seen));

  for (int i = 0; i < m; i++) {
    if (seen[black[i].x][black[i].y][black[i].z])
      continue;

    queue<state> q;
    q.push(black[i]);
    seen[black[i].x][black[i].y][black[i].z] = true;

    x = y = z = false;
    while (!q.empty()) {
      state curr = q.front();
      q.pop();

      if (curr.x == 0) x = true;
      if (curr.y == 0) y = true;
      if (curr.z == 0) z = true;

      if (x && y && z)
        return true;

      for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
          for (int dz = -1; dz <= 1; dz++) {
            int nx = curr.x+dx, ny = curr.y+dy, nz = curr.z+dz;
            if (valid(nx, ny, nz) && !seen[nx][ny][nz] && g[nx][ny][nz]) {
              seen[nx][ny][nz] = true;
              q.push(state(nx, ny, nz));
            }
          }
        }
      }
    }
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> n >> m) {
    if ((n|m) == 0)
      break;
    memset(g, 0, sizeof(g));

    for (int i = 0; i < m; i++) {
      cin >> black[i].x >> black[i].y >> black[i].z;
      g[black[i].x][black[i].y][black[i].z] = 1;
    }

    puts(bfs()? "Benny" : "Willy");
  }

  return 0;
}

