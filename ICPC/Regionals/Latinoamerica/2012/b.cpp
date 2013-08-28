#include <bits/stdc++.h>

using namespace std;

const int mod = int(1e9)+7;

int memo[111][210][210];

int solve(int index, int stones, int curr) {
  if (index == 0) {
    if (stones == 0 && curr == 0)
      return 1;
    return 0;
  }

  if (memo[index][stones][curr] == -1) {
    long long r = solve(index-1, stones, curr / 2) % mod;
    if (stones > 0)
      r = (r + solve(index, stones-1, curr+1)) % mod;
    memo[index][stones][curr] = r;
  }

  return memo[index][stones][curr];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(memo, -1, sizeof(memo));

  int s, b;
  while (cin >> s >> b)
    cout << solve(b-1, s, 0) << '\n';

  return 0;
}
