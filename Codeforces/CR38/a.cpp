#include <bits/stdc++.h>

using namespace std;

int d[111];

int main() {
  int n, a, b, ans;
  scanf("%d", &n);

  for (int i = 0; i < n-1; i++)
    scanf("%d", d+i);
  scanf("%d%d", &a, &b);
  a--, b--;

  ans = 0;
  for (int i = a; i < b; i++)
    ans += d[i];
  printf("%d\n", ans);

  return 0;
}
