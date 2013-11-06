#include <bits/stdc++.h>

using namespace std;

const int maxn = 555;

int n, m, a[maxn][maxn], diag[maxn<<1][maxn], size[maxn<<1];

int solve(int L, int U) {
  int best = 0;

  for (int i = 0; i < n+m-1; i++) {
    if (diag[i][0] > U || diag[i][size[i]-1] < L)
      continue;

    int l = lower_bound(diag[i], diag[i]+size[i], L) - diag[i];
    int r = upper_bound(diag[i], diag[i]+size[i], U) - diag[i] - 1;

    best = max(best, r-l+1);
  }

  return best;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> n >> m) {
    if ((n|m) == 0)
      break;

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> a[i][j];

    for (int i = 0; i < n; i++) {
      for (int j = 0; i+j < n && j < m; j++)
        diag[i][j] = a[i+j][j];
      size[i] = min(n-i, m);
    }

    for (int i = 1; i < m; i++) {
      for (int j = 0; i+j < m && j < n; j++)
        diag[n+i-1][j] = a[j][i+j];
      size[n+i-1] = min(m-i, n);
    }

    int Q, L, U;

    cin >> Q;
    while (Q--) {
      cin >> L >> U;
      cout << solve(L, U) << '\n';
    }
    cout << "-\n";
  }

  return 0;
}
