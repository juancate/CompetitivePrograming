#include <bits/stdc++.h>

using namespace std;

const int INF = int(1e9);

int w, h, d, r[11], c[11], dist[22][22][22][22], memo[11][1<<11];
char b[22][22];

int dr[] = {1,0,-1,0};
int dc[] = {0,1,0,-1};

bool valid(int nr, int nc) {
  return nr >= 0 && nr < h && nc >= 0 && nc < w && b[nr][nc] != 'x';
}

void bfs(int rs, int cs) {
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      dist[rs][cs][i][j] = INF;

  queue< pair<int,int> > Q;
  Q.push(make_pair(rs, cs));
  dist[rs][cs][rs][cs] = 0;

  while (!Q.empty()) {
    int cr = Q.front().first;
    int cc = Q.front().second;
    Q.pop();

    for (int i = 0; i < 4; i++) {
      int nr = cr + dr[i];
      int nc = cc + dc[i];

      if (valid(nr,nc) && dist[rs][cs][nr][nc] == INF) {
        dist[rs][cs][nr][nc] = dist[rs][cs][cr][cc]+1;
        Q.push(make_pair(nr, nc));
      }
    }
  }
}

int dp(int pos, int mask) {
  if (mask == (1<<d)-1)
    return 0;
  if (memo[pos][mask] != -1)
    return memo[pos][mask];

  int ret = INF;

  for (int i = 1; i < d; i++)
    if ((mask & (1 << i)) == 0)
      ret = min(ret, dist[r[pos]][c[pos]][r[i]][c[i]] + dp(i, mask | (1<<i)));

  return memo[pos][mask] = ret;
}

int solve() {
  for (int i = 0; i < d; i++)
    bfs(r[i], c[i]);

  memset(memo, -1, sizeof(memo));
  int ret = dp(0,1);
  return ret >= INF? -1 : ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> w >> h) {
    if ((w|h) == 0)
      break;

    d = 1;

    for (int i = 0; i < h; i++) {
      cin >> b[i];
      for (int j = 0; j < w; j++) {
        if (b[i][j] == '*')
          r[d] = i, c[d++] = j;
        if (b[i][j] == 'o')
          r[0] = i, c[0] = j;
      }
    }

    printf("%d\n", solve());
  }

  return 0;
}

