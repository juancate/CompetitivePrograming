#include <bits/stdc++.h>

using namespace std;

const int maxn = int(1e5);
int L[maxn];

int main() {
  int n, d;
  scanf("%d%d", &n, &d);

  for (int i = 0; i < n; i++)
    scanf("%d", L+i);
  sort(L, L+n);

  int ans = 0;
  for (int i = 0; i < n-1; i++) {
    if (L[i+1]-L[i] <= d)
      ans++, i++;
  }
  printf("%d\n", ans);

  return 0;
}
