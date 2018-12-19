#include <bits/stdc++.h>

using namespace std;

int n, numSCC, dfsNumberCounter;
string ln[2];
vector<int> g[111], dfs_num, dfs_low, S, visited;

void tarjanSCC(int u) {
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
  S.push_back(u);
  visited[u] = 1;
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    if (dfs_num[v] < 0)
      tarjanSCC(v);
    if (visited[v])
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
  }

  if (dfs_low[u] == dfs_num[u]) {
    ++numSCC;
    while (true) {
      int v = S.back(); S.pop_back();
      visited[v] = 0;
      if (u == v) break;
    }
  }
}

void run_tarjan() {
  dfs_num.assign(n, -1); dfs_low.assign(n, 0); visited.assign(n, 0);
  dfsNumberCounter = numSCC = 0;
  for (int i = 0; i < n; i++)
    if (dfs_num[i] < 0)
      tarjanSCC(i);
}

char solve() {
  run_tarjan();

  if (numSCC == n)
    return 'F';

  // check for possible by removing an edge.
  for (int u = 0; u < n; u++) {
    vector<int> a = g[u];
    for (int i = 0; i < a.size(); i++) {
      vector<int> b;
      for (int j = 0; j < a.size(); j++)
        if (i != j) b.push_back(a[j]);
      g[u] = b;
      run_tarjan();

      if (numSCC == n)
        return 'P';

      g[u] = a;
    }
  }

  return 'N';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string a, b;

  while (cin >> a >> b) {
    if (a == "*" && b == "*")
      break;
    cin.get();

    for (int i = 0; i < 2; i++)
      getline(cin, ln[i]);

    map<string,int> m;
    n = 0;
    for (int i = 0; i < 2; i++) {
      stringstream ss(ln[i]);
      string s;
      while (ss >> s) {
        if (s == "," || s == ";")
          continue;
        if (!m.count(s))
          m[s] = n++;
      }
    }

    for (int i = 0; i < n; i++) g[i].clear();

    for (int i = 0; i < 2; i++) {
      stringstream ss(ln[i]);
      string s;
      while (true) {
        int ant = -1;
        while (ss >> s) {
          if (s == "," || s == ";")
            break;
          int c = m[s];
          if (ant > -1)
            g[ant].push_back(c);
          ant = c;
        }
        if (s == ";")
          break;
      }
    }

    for (int i = 0; i < n; i++) if (!g[i].empty()) {
      sort(g[i].begin(), g[i].end());
      g[i].resize(unique(g[i].begin(), g[i].end())-g[i].begin());
    }

    printf("%c\n", solve());
  }

  return 0;
}
