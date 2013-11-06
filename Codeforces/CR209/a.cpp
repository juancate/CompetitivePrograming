#include <bits/stdc++.h>

#define foreach(it,v) \
  for (__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)

using namespace std;

const int maxn = 55;

int n, m, a[maxn][maxn];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> a[i][j];

  int ans = 10;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      if (a[i][j] == 1) {
        ans = min(ans, (i == 0 || j == 0 || i == n-1 || j == m-1)? 2 : 4);
      }
  }

  cout << ans << '\n';

  return 0;
}

