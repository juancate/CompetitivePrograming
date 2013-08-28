#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;
const int maxlgn = 18;

class DSU {
public:
  int pset[maxn], rank[maxn], n;

  void init(int m = 0) {
    n = m;
    for (int i = 0; i < n; i++)
      pset[i] = i, rank[i] = 0;
  }

  int find(int x) {
    return (x == pset[x])? x : pset[x] = find(pset[x]);
  }

  void unite(int x, int y) {
    int px = find(x);
    int py = find(y);

    if (px == py)
      return;

    if (rank[px] < rank[py])
      pset[px] = py;
    else {
      pset[py] = px;
      if (rank[px] == rank[py])
        rank[px]++;
    }
  }
} dsu;

int n, Q, T[maxn], P[maxn][maxlgn], L[maxn], parent_cycle[maxn], cycle_pos[maxn], cycle_size[maxn];
bool seen[maxn];
vector<int> g[maxn];

void calc_level(int u, int level) {
  seen[u] = true;
  L[u] = level;

  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    if (!seen[v]) {
      if (parent_cycle[v] != -1)
        calc_level(v, level);
      else
        calc_level(v, level+1);
    }
  }
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

pair<int,int> query(int p, int q) {
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
    return make_pair(p, q);
  }

  //we compute LCA(p, q) using the values in P
  for(int i = lg; i >= 0; i--) {
    if(P[p][i] != -1 && P[p][i] != P[q][i]) {
      p = P[p][i];
      q = P[q][i];
    }
  }

  return make_pair(T[p], T[q]);
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> n) {
    dsu.init(n);
    for (int i = 0; i < n; i++)
      g[i].clear();

    memset(T, -1, n*sizeof(int));
    memset(seen, 0, n);
    memset(parent_cycle, -1, n*sizeof(int));
    memset(cycle_pos, -1, n*sizeof(int));
    memset(cycle_size, 0, n*sizeof(int));

    for (int i = 0, u; i < n; i++) {
      cin >> u;
      u--;

      if (dsu.find(i) == dsu.find(u)) { // cycle
        T[i] = u;
        int next = i;
        int sz = 0;

        while (!seen[next]) {
          sz++;
          seen[next] = true;
          parent_cycle[next] = T[next];
          next = T[next];
        }

        int next2 = i;
        for (int j = 1;; j++) {
          cycle_pos[next2] = j;
          cycle_size[next2] = sz;
          next2 = T[next2];
          if (next2 == next) break;
        }
      }

      T[i] = u;
      dsu.unite(i, u);
      g[i].push_back(u);
      g[u].push_back(i);
    }

    memset(seen, 0, n);
    for (int i = 0; i < n; i++)
      if (parent_cycle[i] != -1 && !seen[i])
        calc_level(i, 0);

    for (int i = 0; i < n; i++)
      if (!seen[i])
        calc_level(i, 0);

    preprocess();

    cin >> Q;
    while (Q--) {
      int u, v, ans;
      cin >> u >> v;
      u--, v--;

      if (dsu.find(u) != dsu.find(v))
        ans = -1;
      else {
        pair<int,int> node = query(u,v);

        if (node.first == node.second)
          ans = L[u] - L[node.first] + L[v] - L[node.first];
        else {
          int sz = cycle_size[node.first];
          int diff = abs(cycle_pos[node.first] - cycle_pos[node.second]);
          ans = L[u] + L[v] + min(sz - diff, diff);
        }
      }

      cout << ans << '\n';
    }
  }

  return 0;
}
