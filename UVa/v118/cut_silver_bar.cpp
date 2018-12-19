#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  while (scanf("%d", &n)) {
    if (n == 0)
      break;
    int ans = (int)(log(n) / log(2));
    printf("%d\n", ans);
  }

  return 0;
}
