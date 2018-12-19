#include <bits/stdc++.h>

using namespace std;

const int INF = int(1e9);

// General Matching - Blossom algorithm.
// O(VE) - Reference: http://e-maxx.ru/algo/matching_edmonds
// Problem: http://www.codechef.com/problems/SEAGRP

const int maxn = 110;

int n, m;
vector<int> g[maxn];
int match[maxn], p[maxn], base[maxn], q[maxn];
bool used[maxn], blossom[maxn];

int lca(int a, int b) {
  bool used[maxn] = { 0 };

  while (true) {
    a = base[a];
    used[a] = true;
    if (match[a] == -1)
      break;
    a = p[match[a]];
  }

  while (true) {
    b = base[b];
    if (used[b])
      return b;
    b = p[match[b]];
  }
}

void mark_path(int v, int b, int child) {
  while (base[v] != b) {
    blossom[base[v]] = blossom[base[match[v]]] = true;
    p[v] = child;
    child = match[v];
    v = p[match[v]];
  }
}

int find_path(int root) {
  memset(used, false, sizeof used);
  memset(p, -1, sizeof p);

  for (int i = 0; i < n; i++)
    base[i] = i;

  used[root] = true;

  int qh = 0, qt = 0;
  q[qt++] = root;

  while (qh < qt) {
    int v = q[qh++];

    for (int i = 0; i < g[v].size(); i++) {
      int to = g[v][i];

      if (base[v] == base[to] || match[v] == to)
        continue;

      if (to == root || match[to] != -1 && p[match[to]] != -1) {
        int current_base = lca(v, to);

        memset(blossom, false, sizeof blossom);
        mark_path(v, current_base, to);
        mark_path(to, current_base, v);

        for (int j = 0; j < n; j++)
          if (blossom[base[j]]) {
            base[j] = current_base;
            if (!used[j]) {
              used[j] = true;
              q[qt++] = j;
            }
          }
      }
      else if (p[to] == -1) {
        p[to] = v;
        if (match[to] == -1)
          return to;
        to = match[to];
        used[to] = true;
        q[qt++] = to;
      }
    }
  }

  return -1;
}

bool matching() {
  memset(match, -1, sizeof match);

  for (int i = 0; i < n; i++) {
    if (match[i] == -1) {
      int v = find_path(i);
      while (v != -1) {
        int pv = p[v], ppv = match[pv];
        match[v] = pv, match[pv] = v;
        v = ppv;
      }
    }
  }

  for (int i = 0; i < n; i++)
    if (match[i] == -1)
      return false;
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    cin >> n >> m;

    for (int i = 0; i < n; i++)
      g[i].clear();

    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;

      g[u].push_back(v);
      g[v].push_back(u);
    }

    cout << (matching() ? "YES" : "NO") << '\n';
  }

  return 0;
}
