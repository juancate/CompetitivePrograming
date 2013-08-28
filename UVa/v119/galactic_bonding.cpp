#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

int n;
double x[1010], y[1010], d;
vector<int> g[1010];
bool seen[1010];

double dist(int i, int j) {
  return hypot(x[j]-x[i], y[j]-y[i]);
}

void dfs(int u) {
  if (seen[u])
    return;
  seen[u] = true;

  for (int i = 0; i < g[u].size(); i++)
    dfs(g[u][i]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  for (int run = 1; run <= t; run++) {
    cin >> n >> d;
    for (int i = 0; i < n; i++)
      g[i].clear();

    for (int i = 0; i < n; i++) {
      cin >> x[i] >> y[i];
      for (int j = 0; j < i; j++)
        if (d - dist(i,j) > -EPS) {
          g[i].push_back(j);
          g[j].push_back(i);
        }
    }

    memset(seen, 0, n);
    int ans = 0;

    for (int i = 0; i < n; i++)
      if (!seen[i]) {
        ans++;
        dfs(i);
      }

    printf("Case %d: %d\n", run, ans);
  }

  return 0;
}
