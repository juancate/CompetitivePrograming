#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);

  for (int run = 1; run <= t; run++) {
    int n;
    scanf("%d", &n);

    int best, curr;
    scanf("%d", &best);
    for (int i = 1; i < n; i++) {
      scanf("%d", &curr);
      best = max(best, curr);
    }

    printf("Case %d: %d\n", run, best);
  }

  return 0;
}
