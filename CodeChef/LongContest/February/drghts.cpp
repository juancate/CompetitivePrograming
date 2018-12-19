#include <bits/stdc++.h>

using namespace std;

const int N = 50010;

int n, s[N], p[N];
vector<int> g[N];
bool seen[N];
long long cnt;

int pset[N], _rank[N], size[N];

void init(int n) {
  for (int i = 1; i <= n; i++)
    pset[i]=i, _rank[i] = 0, size[i] = s[i];
}

int find(int x) {
  return (x == pset[x])? x : pset[x]=find(pset[x]);
}

void unite(int x, int y) {
  int px = find(x), py = find(y);
  if (px == py) return;
  if (_rank[px] < _rank[py]) {
    pset[px] = py;
    size[py] += size[px];
  }
  else {
    pset[py] = px;
    size[px] += size[py];
    if (_rank[px] == _rank[py])
      _rank[px]++;
  }
}

void bfs(int u) {
  queue<int> q;

  q.push(u);
  seen[u] = true;

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    if (s[u])
      cnt++;

    for (int i = 0; i < g[u].size(); i++) {
      int v = g[u][i];
      if (!seen[v]) {
        p[v] = u;
        seen[v] = true;
        q.push(v);
      }
    }
  }
}

void mark(int u) {
  while (u != -1) {
    seen[u] = true;
    u = p[u];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> s[i+1];

  init(n);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
    unite(u, v);
  }

  long long furik = 0, rubik = 0;
  memset(p, -1, sizeof p);
  memset(seen, 0, sizeof seen);

  for (int i = 1; i <= n; i++)
    if (s[i] && !seen[i]) {
      cnt = 0;
      bfs(i);
      furik += (cnt * (cnt - 1)) / 2;
    }

  if (furik != 0) {
    memset(seen, 0, sizeof seen);
    for (int i = 1; i <= n; i++) {
      int total_size = size[find(i)];
      if (s[i] && !seen[i] && total_size > 1)
        mark(i);
    }

    for (int i = 1; i <= n; i++)
      rubik += seen[i];
  }

  cout << furik << ' ' << rubik << '\n';

  return 0;
}
