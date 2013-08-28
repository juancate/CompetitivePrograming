#include <bits/stdc++.h>

using namespace std;

const int maxn = 1510;

int n;
bool seen[maxn][maxn], g[maxn][maxn];

int dr[] = {1,0,-1,0};
int dc[] = {0,1,0,-1};

inline bool valid(int nr, int nc) {
  return nr >= 0 && nr < 4*n+1 && nc >= 0 && nc < 5*n+1 && g[nr][nc];
}

void bfs(int i, int j) {
  queue< pair<int,int> > Q;
  Q.push(make_pair(i,j));
  seen[i][j] = true;

  while (!Q.empty()) {
    int r = Q.front().first;
    int c = Q.front().second;
    Q.pop();

    for (int k = 0; k < 4; k++) {
      int nr = r + dr[k];
      int nc = c + dc[k];

      if (valid(nr, nc) && !seen[nr][nc]) {
        seen[nr][nc] = true;
        Q.push(make_pair(nr,nc));
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> n) {
    memset(g, 1, sizeof(g));
    for (int i = 0, x = 2; i < 2*n-1; i++, x += 2) {
      for (int j = 0, y = 2+2*(i&1); j < n; j++, y += 5) {
        char ch;
        cin >> ch;

        if (ch == 'H')
          g[x][y] = g[x][y-1] = g[x][y-2] = g[x][y+1] = g[x][y+2] = 0;
        else
          g[x][y] = g[x-1][y] = g[x-2][y] = g[x+1][y] = g[x+2][y] = 0;
      }
    }

    int components = 0;
    memset(seen, 0, sizeof(seen));
    for (int i = 0; i < 4*n+1; i++)
      for (int j = 0; j < 5*n+1; j++)
        if(!seen[i][j] && g[i][j]) {
          bfs(i,j);
          components++;
        }

    cout << components-1 << '\n';
  }

  return 0;
}
