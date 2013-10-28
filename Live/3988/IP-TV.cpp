#include <bits/stdc++.h>

using namespace std;

const int maxn = 2010;
const int max_edges = 50010;

struct edge {
  int from, to, cost;
  edge(int f=0, int t=0, int c=0) :
    from(f), to(t), cost(c) {}
  bool operator<(const edge& e) const {
    return cost < e.cost;
  }
} E[max_edges];

int N, M;

int pset[maxn], rank[maxn];

void init(int n) { for (int i = 0; i < n; i++) pset[i]=i, rank[i] = 0; }
int find(int x) { return (x == pset[x])? x : pset[x]=find(pset[x]); }
void unite(int x, int y) {
  int px = find(x), py = find(y);
  if (px == py) return;
  if (rank[px] < rank[py])
    pset[px] = py;
  else {
    pset[py] = px;
    if (rank[px] == rank[py])
      rank[px]++;
  }
}
bool same_set(int a, int b) {
  return find(a) == find(b);
}

int kruskal() {
  int done = 0, ans = 0;

  for (int i = 0; i < M && done < N-1; i++) {
    int u = E[i].from, v = E[i].to;
    if (!same_set(u, v)) {
      unite(u,v);
      done++;
      ans += E[i].cost;
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    map<string,int> cities;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
      int cost;
      string u, v;
      cin >> u >> v >> cost;
      if (!cities.count(u)) cities[u] = cities.size()-1;
      if (!cities.count(v)) cities[v] = cities.size()-1;

      E[i].from = cities[u];
      E[i].to = cities[v];
      E[i].cost = cost;
    }
    sort(E, E+M);

    init(N);
    cout << kruskal() << '\n';

    if (t > 0)
      cout << '\n';
  }

  return 0;
}
