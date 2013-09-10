#include <bits/stdc++.h>

using namespace std;

const int INF = int(1e9);
const int maxn = 1010;
const int mod = INT_MAX;

int n, dist[maxn][maxn];
long long dp[maxn][maxn];
char grid[maxn][maxn];

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

bool valid(int nr, int nc) {
  return nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] != '#';
}

bool bfs() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      dist[i][j] = INF;
  dist[0][0] = 0;

  queue< pair<int,int> > q;
  q.push(make_pair(0,0));

  while (!q.empty()) {
    int r = q.front().first;
    int c = q.front().second;
    q.pop();

    if (r == n-1 && c == n-1)
      return true;

    for (int i = 0; i < 4; i++) {
      int nr = dr[i] + r;
      int nc = dc[i] + c;

      if (valid(nr, nc) && dist[nr][nc] == INF) {
        dist[nr][nc] = dist[r][c]+1;
        q.push(make_pair(nr, nc));
      }
    }
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  memset(dp, 0, sizeof(dp));

  for (int i = 0; i < n; i++)
    cin >> grid[i];

  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == '.') {
        if (i) dp[i][j] = dp[i-1][j];
        if (j) dp[i][j] = dp[i][j] + dp[i][j-1];

        if (dp[i][j] >= mod) dp[i][j] -= mod;
      }
    }
  }

  if (dp[n-1][n-1])
    cout << dp[n-1][n-1] << '\n';
  else
    cout << (bfs()? "THE GAME IS A LIE\n" : "INCONCEIVABLE\n");

  return 0;
}
