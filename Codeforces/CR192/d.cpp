#include <bits/stdc++.h>

using namespace std;

const int maxn = 1010;
const int INF = int(1e9);

int n, m;
char g[maxn][maxn];
int dist[maxn][maxn];

int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

void bfs(int r, int c) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      dist[i][j] = INF;

  queue< pair<int,int> > Q;
  Q.push(make_pair(r, c));
  dist[r][c] = 0;

  while (!Q.empty()) {
    r = Q.front().first;
    c = Q.front().second;
    Q.pop();

    for (int i = 0; i < 4; i++) {
      int nr = r + dr[i];
      int nc = c + dc[i];

      if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
        if (g[nr][nc] == 'T') continue;
        if (dist[nr][nc] == INF) {
          dist[nr][nc] = dist[r][c] + 1;
          Q.push(make_pair(nr, nc));
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int re, ce, rs, cs;

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> g[i];
    for (int j = 0; j < m; j++) {
      if (g[i][j] == 'E')
        re = i, ce = j;
      if (g[i][j] == 'S')
        rs = i, cs = j;
    }
  }

  bfs(re, ce);
  int start_dist = dist[rs][cs];
  int ans = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (isdigit(g[i][j]) && dist[i][j] <= start_dist)
        ans += g[i][j] - '0';
    }
  }

  cout << ans << endl;

  return 0;
}
