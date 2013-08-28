#include <bits/stdc++.h>

using namespace std;

int n, k;
long long memo[18][2];

long long solve(int index, int zero) {
  if (index == n)
    return 1LL;

  if (memo[index][zero] != -1)
    return memo[index][zero];

  int start = (zero || index == 0)? 1 : 0;
  long long ret = 0;
  for (int i = start; i < k; i++) {
    ret += solve(index+1, i == 0);
  }

  return memo[index][zero] = ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k;
  memset(memo, -1, sizeof(memo));
  cout << solve(0, 0) << '\n';

  return 0;
}
