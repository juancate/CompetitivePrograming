#include <bits/stdc++.h>

using namespace std;

long long memo[510];

long long solve(int n) {
  if (n <= 2)
    return memo[n] = 0;

  if (memo[n] != -1)
    return memo[n];

  long long r = 0;
  for (int i = 1; i < n; i++) {
    if (i > n-i) {
      r += solve(n-i);
    }
  }

  return memo[n] = r;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  memset(memo, -1, sizeof(memo));
  cout << solve(n) << '\n';

  return 0;
}
