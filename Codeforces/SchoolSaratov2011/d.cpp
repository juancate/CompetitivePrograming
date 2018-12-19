#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int n, m;
  scanf("%d%d", &n, &m);

  vector< vector<int> > a(n, vector<int>(m));

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      scanf("%d", &a[i][j]);

  vector<int> sons(3);
  scanf("%d%d%d", &sons[0], &sons[1], &sons[2]);
  sort(sons.begin(), sons.end());

  int ans = 0;

  for (int k = 0; k < 2; k++) {

    for (int x1 = 1; x1 < m; x1++) {
      for (int x2 = x1+1; x2 < m; x2++) {
        vector<int> cnt(3);
        for (int x = 0; x < x1; x++)
          for (int y = 0; y < n; y++)
            cnt[0] += a[y][x];
        for (int x = x1; x < x2; x++)
          for (int y = 0; y < n; y++)
            cnt[1] += a[y][x];
        for (int x = x2; x < m; x++)
          for (int y = 0; y < n; y++)
            cnt[2] += a[y][x];
        sort(cnt.begin(), cnt.end());
        if (cnt == sons)
          ans++;
      }
    }

    vector< vector<int> > b(m, vector<int>(n));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        b[j][i] = a[i][j];
    swap(a, b);
    swap(n, m);
  }

  printf("%d\n", ans);

  return 0;
}
