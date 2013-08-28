#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  while(scanf("%d", &n)) {
    if(n == 0)
      break;
    n--;
    int ans = n * (n+1) * (n+2) * (n+3);
    ans /= 24;
    printf("%d\n", ans);
  }
  return 0;
}
