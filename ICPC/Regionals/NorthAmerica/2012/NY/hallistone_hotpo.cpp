#include <bits/stdtr1c++.h>

using namespace std;
using namespace std::tr1;

unordered_map<int,int> memo;

int solve(int x) {
  if (memo.count(x))
    return memo[x];
  if (x & 1)
    memo[x] = max(x, solve(3*x+1));
  else
    memo[x] = max(x, solve(x >> 1));
  return memo[x];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memo[1] = 1;

  int P, n, tc;
  cin >> P;

  while (P--) {
    cin >> tc >> n;
    cout << tc << ' ' << solve(n) << '\n';
  }

  return 0;
}
