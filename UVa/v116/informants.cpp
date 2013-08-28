#include <bits/stdc++.h>

using namespace std;

bool a[22];

int main() {
  int n, m;

  while (scanf("%d%d", &n, &m)) {
    if ((n|m) == 0)
      break;

    memset(a, 1, n);
    for (int i = 0, u, v; i < m; i++) {
      scanf("%d%d", &u, &v);
      if (v < 0)
        a[-v-1] = false;
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
      ans += a[i];
    printf("%d\n", ans);
  }

  return 0;
}
