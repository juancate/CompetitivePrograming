#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);

  for (int run = 1; run <= t; run++) {
    int R, L, x1, x2, y1, y2;
    scanf("%d", &R);

    L = 5 * R;
    x1 = (-L * 45) / 100;
    x2 = (L * 55) /100;
    y1 = (-L * 60) / 100 / 2;
    y2 = -y1;

    printf("Case %d:\n", run);
    printf("%d %d\n", x1, y2);
    printf("%d %d\n", x2, y2);
    printf("%d %d\n", x2, y1);
    printf("%d %d\n", x1, y1);
  }
  return 0;
}
