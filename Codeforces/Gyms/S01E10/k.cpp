#include <bits/stdc++.h>

using namespace std;

const int maxn = 111;

int n, a[maxn], b[maxn];

void solve() {
  if (n == 1) {
    b[0] = a[0];
    return;
  }

  int l = 0, r = n-1;
  for (int i = n-1; i >= 0; i -= 2) {
    b[l++] = a[i-1];
    b[r--] = a[i];
  }
}

int main() {
  freopen("cubes.in", "r", stdin);

  int t;
  scanf("%d", &t);

  for (int tc = 1; tc <= t; tc++) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%d", a+i);
    sort(a, a+n);

    printf("Case %d:\n", tc);

    solve();

    printf("%d", b[0]);
    for (int i = 1; i < n; i++)
      printf(" %d", b[i]);
    printf("\n");
  }

  return 0;
}
