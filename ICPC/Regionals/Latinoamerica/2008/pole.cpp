#include <bits/stdc++.h>

using namespace std;

const int maxn = 1010;

int n, a[maxn], p[maxn], ans[maxn];

bool solve() {
  for (int i = 0; i < n; i++) {
    int v = p[i];
    if (i + v >= n || i + v < 0)
      return false;
    if (ans[i+v] != 0)
      return false;
    ans[i+v] = a[i];
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> n) {
    if (n == 0)
      break;

    for (int i = 0; i < n; i++)
      cin >> a[i] >> p[i];

    memset(ans, 0, sizeof ans);
    if (!solve())
      cout << -1 << '\n';
    else {
      cout << ans[0];
      for (int i = 1; i < n; i++)
        cout << ' ' << ans[i];
      cout << '\n';
    }
  }

  return 0;
}
