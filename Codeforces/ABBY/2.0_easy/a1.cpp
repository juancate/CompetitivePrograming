#include <bits/stdc++.h>

using namespace std;

int n, a[111][111];
bool s[111][111];

int main() {
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", &a[i][j]);

  int sum = 0;

  for (int i = 0; i < n; i++) {
    if (!s[i][i]) {
      sum += a[i][i];
      s[i][i] = true;
    }
    if (!s[i][n-i-1]) {
      sum += a[i][n-i-1];
      s[i][n-i-1] = true;
    }
    if (!s[i][n>>1]) {
      sum += a[i][n>>1];
      s[i][n>>1] = true;
    }
    if (!s[n>>1][i]) {
      sum += a[n>>1][i];
      s[n>>1][i] = true;
    }
  }

  printf("%d\n", sum);

  return 0;
}
