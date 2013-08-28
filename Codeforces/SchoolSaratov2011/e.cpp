#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t, n;
  scanf("%d", &t);

  while (t--) {
    scanf("%d", &n);
    printf("%d\n", (n & 1)? 0 : 1);
  }

  return 0;
}
