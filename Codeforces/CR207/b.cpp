#include <bits/stdc++.h>

#define foreach(it,v) \
  for (__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)

using namespace std;

const int maxn = 100010;

int c[maxn];
vector<int> g[maxn];

void bfs(int u) {
  queue<int> q;
  c[u] = 0;
  q.push(u);

  while (!q.empty()) {
    int curr = q.front();
    q.pop();

    for (int i = 0; i < g[curr].size(); i++) {
      int v = g[curr][i];
      if (c[v] >= 0) continue;
      int color = (c[curr] + 1) % 3;
      for (int j = 0; j < g[v].size(); j++)
        if (c[g[v][j]] == color) {
          color = (color + 1) % 3;
          break;
        }
      c[v] = color;
      q.push(v);
    }
  }
}

void add_edge(int u, int v) {
  g[u].push_back(v);
  g[v].push_back(u);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int u, v, s;
    cin >> u >> v >> s;
    u--, v--, s--;
    add_edge(u, v);
    add_edge(u, s);
    add_edge(v, s);
  }

  memset(c, -1, sizeof(c));

  for (int i = 0; i < n; i++)
    if (c[i] < 0)
      bfs(i);
  for (int i = 0; i < n; i++)
    cout << c[i]+1 << ' ';
  cout << '\n';

  return 0;
}

