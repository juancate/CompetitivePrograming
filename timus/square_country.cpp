#include <bits/stdc++.h>

using namespace std;

int memo[60010];

int get_root(int x) {
  return (int)floor(sqrt(x));
}

int solve(int n) {
  if (memo[n] != -1) return memo[n];

  int r = get_root(n);
  int s = get_root(n / 4) + 1;

  memo[n] = int(1e9);
  for (int i = s; i <= r; i++)
    memo[n] = min(memo[n], solve(n-i*i)+1);

  return memo[n];
}

int main() {
  int n;
  scanf("%d", &n);

  memset(memo, -1, sizeof(memo));
  memo[0] = 0;
  printf("%d\n", solve(n));

  return 0;
}
