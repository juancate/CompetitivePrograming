#include <bits/stdc++.h>

using namespace std;

int a[111][111], c[111], ind[111], p[10010];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
      cin >> p[i];

    for (int i = 0; i < n; i++) {
      cin >> c[i];
      ind[i] = c[i]-1;
      for (int j = 0; j < c[i]; j++)
        cin >> a[i][j];
      sort(a[i], a[i]+c[i]);
    }

    long long ans = 0;
    for (int i = 0; i < m; i++) {
      if (ind[p[i]] >= 0) {
        ans += a[p[i]][ind[p[i]]];
        ind[p[i]]--;
      }
    }
    cout << ans << '\n';
  }

  return 0;
}
