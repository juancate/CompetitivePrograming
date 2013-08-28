#include <bits/stdc++.h>

using namespace std;

// Problem: 6137 - Game of Tiles
// Algorithm: Bipartite Matching - Hopcroft-Karp

const int INF = int(1e9);
const int maxn = 5010;

int n, m, matching, dist[maxn], match[maxn], NIL;
vector<int> g[maxn];

// n: left set, m: right set, NIL: n+m

bool bfs() {
  queue<int> Q;

  for (int v = 0; v < n; v++) {
    dist[v] = INF;
    if (match[v] == NIL) {
      dist[v] = 0;
      Q.push(v);
    }
  }

  dist[NIL] = INF;

  while (!Q.empty()) {
    int v = Q.front();
    Q.pop();
    if (dist[v] < dist[NIL]) {
      for (int i = 0; i < g[v].size(); i++) {
        int u = g[v][i];
        if (dist[match[u]] == INF) {
          dist[match[u]] = dist[v]+1;
          Q.push(match[u]);
        }
      }
    }
  }

  return dist[NIL] != INF;
}

bool dfs(int v) {
  if (v != NIL) {
    for (int i = 0; i < g[v].size(); i++) {
      int u = g[v][i];
      if (dist[match[u]] == dist[v]+1 && dfs(match[u])) {
        match[u] = v;
        match[v] = u;
        return true;
      }
    }
    dist[v] = INF;
    return false;
  }
  return true;
}

int hopcroft_karp() {
  NIL = n+m;
  for (int i = 0; i < n+m; i++)
    match[i] = NIL;

  matching = 0;
  for (int v = 0; v < n; v++) {
    for (int i = 0; i < g[v].size(); i++) {
      int u = g[v][i];
      if (match[u] == NIL) {
        matching++;
        match[u] = v;
        match[v] = u;
        break;
      }
    }
  }

  while (bfs()) {
    for (int v = 0; v < n; v++)
      if (match[v] == NIL && dfs(v))
        matching++;
  }
  return matching;
}

int R, C, ones, twos;
string grid[55];
bool seen[55][55];

int dr[] = {1,0,-1,0};
int dc[] = {0,1,0,-1};

inline
bool valid(int r, int c) {
  return r >= 0 && r < R && c >= 0 && c < C && !seen[r][c] && grid[r][c] == '.';
}

void dfs_paint(int r, int c, int color) {
  if (color == 1) ones++;
  else twos++;

  seen[r][c] = 1;
  for (int i = 0; i < 4; i++) {
    int nr = r + dr[i];
    int nc = c + dc[i];

    if (valid(nr,nc)) {
      if (color == 1)
        g[r*C+c].push_back(nr*C+nc+n);
      else
        g[nr*C+nc].push_back(r*C+c+n);
    }
  }

  int next_color = (color == 1)? 2 : 1;
  for (int i = 0; i < 4; i++) {
    int nr = r + dr[i];
    int nc = c + dc[i];

    if (valid(nr, nc))
      dfs_paint(nr,nc,next_color);
  }
}

int solve() {
  n = R*C;
  m = R*C;
  memset(seen, 0, sizeof(seen));

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (seen[i][j] || grid[i][j] == 'X')
        continue;

      for (int k = 0; k < n; k++)
        g[k].clear();

      ones = twos = 0;
      dfs_paint(i,j,1);

      if (!(ones == twos && ones == hopcroft_karp()))
        return 1;
    }
  }

  return 2;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> R >> C) {
    for (int i = 0; i < R; i++)
      cin >> grid[i];

    cout << solve() << '\n';
  }

  return 0;
}
