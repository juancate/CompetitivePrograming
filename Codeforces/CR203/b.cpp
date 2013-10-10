#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;

int n, out[maxn], in[maxn], parent[maxn], size[maxn];
int type[maxn];
vector<int> g[maxn];
bool seen[maxn];

void dfs(int u, int p = -1) {
  if (seen[u])
    return;
  if (type[u] == 0)
    seen[u] = 1;

  int curr = (p == -1)? 1 : size[p]+1;

  if (curr > size[u]) {
    size[u] = curr;
    parent[u] = p;
  }

  if (type[u] == 1)
    return;

  for (int j = 0; j < g[u].size(); j++) {
    int v = g[u][j];
    if (type[v] == 0) {
      if (out[v] == 1)
        dfs(v, u);
    }
    else dfs(v, u);
  }
}

void print(int u) {
  if (u == -1)
    return;
  print(parent[u]);
  cout << u+1 << ' ';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> type[i];
    size[i] = seen[i] = out[i] = in[i] = 0;
    parent[i] = -1;
  }

  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    if (v != 0) {
      g[v-1].push_back(i);
      if (type[v-1] == 0)
        in[i]++;
      out[v-1]++;
    }
  }

  for (int i = 0; i < n; i++) {
    if (type[i] == 0) {
      if (out[i] > 1)
        for (int j = 0; j < g[i].size(); j++) {
          int v = g[i][j];
          in[v]--;
        }
    }
  }

  for (int u = 0; u < n; u++) {
    if (in[u] == 0 && out[u] < 2 && !seen[u]) {
      dfs(u);
    }
  }

  int best = -1;
  for (int i = 0; i < n; i++) {
    if (type[i] == 1) {
      if (best == -1 || size[best] < size[i])
        best = i;
    }
  }
  cout << size[best] << '\n';
  print(best);
  cerr << '\n';

  return 0;
}
