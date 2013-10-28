#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;

// DP: Reduce problem to 1D

vector< vector<int> > g;
int n, m, r[maxn];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> n >> m) {
    if ((n|m) == 0)
      break;
    g.clear();
    g.resize(n+2, vector<int>(m+2));

    for (int i = 0; i < n; i++) {
      for (int j = 2; j <= m+1; j++) {
        cin >> g[i][j];
        g[i][j] = max(g[i][j-1], g[i][j] + g[i][j-2]);
      }
    }

    memset(r, 0, sizeof r);

    for (int i = 0; i < n; i++)
      r[i+2] = g[i][m+1];
    for (int i = 2; i <= n+1; i++)
      r[i] = max(r[i-1], r[i] + r[i-2]);

    cout << r[n+1] << '\n';
  }

  return 0;
}
