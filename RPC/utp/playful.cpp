#include <bits/stdc++.h>

using namespace std;

const int N = 11;

int n, m, t, a[N][N], b[N][N];

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int tc;
  cin >> tc;

  while (tc--) {
    cin >> t >> n >> m;

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> a[i][j];

    int total = n+m;
    int best = -int(1e9);

    for (int mask = 0; mask < (1 << total); mask++) {
      int len = __builtin_popcount(mask);

      if (len == t) {
        int curr = 0;
        memcpy(b, a, sizeof a);

        for (int i = 0; i < total; i++) {
          if ((mask & (1 << i))) {
            if (i < n) { // row
              for (int j = 0; j < m; j++) {
                curr += b[i][j];
                b[i][j] = 0;
              }
            } else { // col
              int k = i - n;
              for (int j = 0; j < n; j++) {
                curr += b[j][k];
                b[j][k] = 0;
              }
            }
          }
        }

        best = max(best, curr);
      }
    }

    cout << best << '\n';
  }

  return 0;
}
