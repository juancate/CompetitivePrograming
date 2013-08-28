#include <bits/stdc++.h>

using namespace std;

int limit, n;

void solve(int x, int depth) {
  int i;
  cout << x << '\n';
  for (i = 0; i < n; i++) {
    if ((depth & (1 << i)) == 0)
      break;
  }
  if (i == n)
    return;
  int next = limit-1;
  next = next ^ (1 << i);
  next = next ^ x;
  solve(next, depth+1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    cin >> n;
    limit = 1 << n;
    solve(0, 0);
  }

  return 0;
}
