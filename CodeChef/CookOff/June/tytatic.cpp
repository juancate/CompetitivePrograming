#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;

int to[maxn], skills[maxn], tail[maxn], n, m, last;
vector<int> g[maxn];

void dfs(int u, int parent = -1) {
  to[u] = last++;
  for (int i = 0; i < g[u].size(); i++)
    if (g[u][i] != parent)
      dfs(g[u][i], u);
  tail[u] = last;
}

class BIT {
public:
  int t[maxn], n;
  BIT(int m) {
    n = ++m;
    fill(t, t+n, 0);
  }

  int rsq(int idx) {
    int sum = 0;
    for (; idx; idx -= (idx & -idx))
      sum += t[idx];
    return sum;
  }

  int rsq(int a, int b) {
    return rsq(b) - (a == 1 ? 0 : rsq(a-1));
  }

  void adjust(int k, int v) {
    for (; k <= n; k += (k & -k))
      t[k] += v;
  }
};

char op[10];

int main() {
  scanf("%d%d", &n, &m);

  for (int i = 1; i <= n; i++)
    scanf("%d", skills+i);

  for (int i = 1, u, v; i < n; i++) {
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }

  last = 1;
  dfs(1);
  BIT tree(n+1);

  for (int i = 1; i <= n; i++)
    tree.adjust(to[i], skills[i]);

  while (m--) {
    scanf("%s", op);
    if (op[0] == 'Q') {
      int ans, u;
      scanf("%d", &u);
      ans = tree.rsq(to[u], tail[u]-1);
      printf("%d\n", ans);
    }
    else {
      int u, x;
      scanf("%d%d", &u, &x);
      tree.adjust(to[u], x-tree.rsq(to[u],to[u]));
    }
  }

  return 0;
}
