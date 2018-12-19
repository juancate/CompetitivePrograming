#include <bits/stdc++.h>

using namespace std;

const int maxn = 710;

const int INF = int(1e9);

const int dr[] = {1, 0, -1, 0};
const int dc[] = {0, -1, 0, 1};

int n, m, dist[maxn<<1], match[maxn<<1], NIL;
vector<int> g[maxn];

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

  int matching = 0;
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

char grid[30][30];
int gid[30][30], hid[30][30];
int minDist[30][30], total_dist[maxn][maxn];

void clear_dist(int sz) {
  for (int i = 0; i < sz; i++)
    for (int j = 0; j < sz; j++)
      minDist[i][j] = INF;
}

bool check(int tl) {
  for (int i = 0; i < n; i++) {
    g[i].clear();
    for (int j = 0; j < m; j++) {
      if (total_dist[i][j] <= tl)
        g[i].push_back(j + n);
    }
  }

  return hopcroft_karp() == m;
}

void solve() {
  int g, h, size;
  scanf("%d", &size);

  g = h = 0;

  for (int i = 0; i < size; i++) {
    scanf("%s", grid[i]);
    for (int j = 0; j < size; j++) {
      if (grid[i][j] == 'G')
        gid[i][j] = g++;
      else if (grid[i][j] == 'H')
        hid[i][j] = h++;
    }
  }

  n = g;
  m = h;
  int max_dist = -INF;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      total_dist[i][j] = INF;

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (grid[i][j] == 'G') {
        int curr = gid[i][j];

        clear_dist(size);
        queue< pair<int,int> > Q;
        minDist[i][j] = 0;
        Q.push(make_pair(i,j));

        while (!Q.empty()) {
          int r = Q.front().first;
          int c = Q.front().second;
          Q.pop();

          if (grid[r][c] == 'H') {
            total_dist[curr][hid[r][c]] = 2 * (minDist[r][c] + 1);
            max_dist = max(max_dist, total_dist[curr][hid[r][c]]);
          }

          for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr >= 0 && nr < size && nc >= 0 && nc < size) {
              if (minDist[nr][nc] == INF && grid[nr][nc] != '#') {
                minDist[nr][nc] = minDist[r][c] + 1;
                Q.push(make_pair(nr, nc));
              }
            }
          }
        }
      }
    }
  }

  int lo = 0, hi = max_dist;
  int ans = 0;

  while (lo < hi) {
    int mid = lo + (hi - lo) / 2;

    if (check(mid))
      hi = mid;
    else
      lo = mid+1;
  }

  if (check(lo))
    printf("%d\n", lo);
  else
    printf("Vuter Dol Kupokat\n");
}

int main() {
  int t;
  scanf("%d", &t);

  for (int tc = 1; tc <= t; tc++) {
    printf("Case %d: ", tc);
    solve();
  }

  return 0;
}
