#include <bits/stdc++.h>

using namespace std;

int n, m, a[111], b[111];

bool solve(int v) {
  int extra_cnt = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > v)
      return false;
    if (2 * a[i] <= v)
      extra_cnt++;
  }

  if (extra_cnt < 1)
    return false;

  for (int i = 0; i < m; i++)
    if (b[i] <= v)
      return false;
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < m; i++)
    cin >> b[i];

  int ans = -1;
  for (int i = 0; i <= 200; i++)
    if (solve(i)) {
      ans = i;
      break;
    }
  cout << ans << '\n';

  return 0;
}
