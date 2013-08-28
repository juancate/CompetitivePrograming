#include <bits/stdc++.h>

using namespace std;

const int maxn = 111;
const int INF = int(1e9);

int N, M, pigs[11][11];
string b[10];

int dr[] = {0,1,0,-1};
int dc[] = {1,0,-1,0};

int n, m, matching, dist[maxn], match[maxn], NIL;
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M;

  n = m = 0;
  for (int i = 0; i < N; i++) {
    cin >> b[i];
    for (int j = 0; j < M; j++) {
      if (b[i][j] == 'P') pigs[i][j] = m++;
      if (b[i][j] == 'W') n++;
    }
  }

  int pos = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (b[i][j] == 'W') {
        pos++;
        for (int k = 0; k < 4; k++) {
          int ni = i + dr[k];
          int nj = j + dc[k];
          if (ni >= 0 && ni < N && nj >= 0 && nj < M)
            if (b[ni][nj] == 'P')
              g[pos-1].push_back(n+pigs[ni][nj]);
        }
      }
    }
  }
  cout << hopcroft_karp() << '\n';

  return 0;
}
