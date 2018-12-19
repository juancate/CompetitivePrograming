#include <bits/stdc++.h>

using namespace std;

// 1471 - Tree
// Lowest Common Ancestor

const int maxn = 50010;
const int maxlgn = 16;

int n, m, root, T[maxn], P[maxn][maxlgn], L[maxn], cost[maxn], dist[maxn];

int calc_level(int u) {
  if (L[u] > -1) return L[u];
  return L[u] = calc_level(T[u]) + 1;
}

int calc_sum(int u) {
  if (dist[u] > -1) return dist[u];
  return dist[u] = calc_sum(T[u]) + cost[u];
}

void preprocess() {
  for(int i = 0; i < n; i++)
    for(int j = 0; (1 << j) < n; j++)
      P[i][j] = -1;

  //the first ancestor of every node i is T[i]
  for(int i = 0; i < n; i++)
    P[i][0] = T[i];

  for(int j = 1; (1 << j) < n; j++)
    for(int i = 0; i < n; i++)
      if(P[i][j-1] != -1)
        P[i][j] = P[P[i][j-1]][j-1];

}

int query(int p, int q) {
  int lg, i;

  //if p is situated on a higher level than q then we swap them
  if(L[p] < L[q])
    swap(p, q);

  //we compute the value of [log(L[p)]
  for(lg = 1; (1 << lg) <= L[p]; lg++);
  lg--;

  //we find the ancestor of node p situated on the same level
  //with q using the values in P
  for(int i = lg; i >= 0; i--) {
    if(L[p] - (1 << i) >= L[q]) {
      p = P[p][i];
    }
  }

  if(p == q) {
    return p;
  }

  //we compute LCA(p, q) using the values in P
  for(int i = lg; i >= 0; i--) {
    if(P[p][i] != -1 && P[p][i] != P[q][i]) {
      p = P[p][i];
      q = P[q][i];
    }
  }

  return T[p];
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  memset(T, -1, sizeof(T));

  for (int i = 1, u, v, w; i < n; i++) {
    cin >> u >> v >> w;
    if (T[u] != -1)
      swap(u, v);
    T[u] = v;
    cost[u] = w;
  }

  memset(L, -1, n*sizeof(int));
  memset(dist, -1, n*sizeof(int));

  for (int i = 0; i < n; i++) if (T[i] < 0) {
    root = i;
    break;
  }

  L[root] = dist[root] = 0;
  for (int i = 0; i < n; i++) {
    calc_sum(i);
    calc_level(i);
  }

  preprocess();

  cin >> m;

  while (m--) {
    int u, v;
    cin >> u >> v;

    int lca = query(u, v);
    int ans = dist[u] + dist[v] - 2*dist[lca];

    cout << ans << '\n';
  }

  return 0;
}
