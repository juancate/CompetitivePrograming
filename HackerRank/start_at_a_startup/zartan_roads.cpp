#include <bits/stdc++.h>

using namespace std;

const int maxn = 44;
const int INF = int(1e9);

int N, R, dist[maxn], out_degree[maxn];
vector<int> g[maxn];
bool in_cycle[maxn];

bool bfs(int start) {
  for (int i = 0; i < N; i++)
    dist[i] = INF;

  queue<int> Q;
  Q.push(start);
  dist[start] = 0;
  bool first = 1;

  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();

    if (u == start && !first)
      return true;
    first = false;

    for (int i = 0; i < g[u].size(); i++) {
      int v = g[u][i];
      if (u != v && (dist[v] == INF || v == start)) {
        dist[v] = dist[u]+1;
        Q.push(v);
      }
    }
  }
  return false;
}

bool solve() {
  for (int i = 0; i < N; i++)
    if (bfs(i) || in_cycle[i])
        return true;
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> R;
  memset(in_cycle, 0, sizeof(in_cycle));
  for (int i = 0, u, v; i < R; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    if (u == v) in_cycle[u] = true;
  }

  cout << (solve()? "YES" : "NO")  << '\n';

  return 0;
}

