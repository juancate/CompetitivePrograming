#include <bits/stdc++.h>

using namespace std;

int memo[111][10010], s[111], n, x;

double solve(int id, int share) {
  if (id == n) {
    if (share > 5000)
      return round(10000 * (double)s[x] / (double)share);
    return 0;
  }

  if (memo[id][share] != -1)
    return memo[id][share];

  double profit = 0.0;
  if (share > 5000)
    profit = round(10000 * (double)s[x] / (double)share);

  double ret = 0.0;
  if (id == x)
    ret = max(profit, solve(id+1, share));
  else
    ret = max(profit, max(solve(id+1, share), solve(id+1, share+s[id])));

  return memo[id][share] = ret;
}

int main() {
  while (scanf("%d%d", &n, &x)) {
    if ((n|x) == 0)
      break;
    x--;

    for (int i = 0, a, b; i < n; i++) {
      scanf("%d.%d", &a, &b);
      s[i] = a*100 + b;
    }

    if (s[x] > 5000) {
      printf("100.00\n");
      continue;
    }

    memset(memo, -1, sizeof(memo));
    int ans = (int)round(solve(0, s[x]));
    printf("%d.%02d\n", ans/100, ans%100);
  }
  return 0;
}
