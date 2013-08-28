#include <bits/stdc++.h>

using namespace std;

const int INF = int(1e9);
const int maxn = 50010;

int n, m, dist[maxn<<1], match[maxn<<1], NIL;
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int p;
  cin >> n >> m >> p;

  for (int i = 0, u, v; i < p; i++) {
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v+n);
  }
  cout << hopcroft_karp() << '\n';

  return 0;
}
