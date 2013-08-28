#include <bits/stdc++.h>

using namespace std;

int get_time(int y, int m, int d) {
  if (m < 3)
    y--, m += 12;
  return 365 * y + y/4 - y/100 + y/400 + d + (153 * m + 8) / 5;
}

int main() {
  int yy1, mm1, dd1, yy2, mm2, dd2;

  scanf("%d:%d:%d", &yy1, &mm1, &dd1);
  scanf("%d:%d:%d", &yy2, &mm2, &dd2);

  cout << abs(get_time(yy1, mm1, dd1) - get_time(yy2, mm2, dd2)) << '\n';

  return 0;
}
