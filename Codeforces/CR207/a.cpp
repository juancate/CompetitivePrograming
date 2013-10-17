#include <bits/stdc++.h>

#define foreach(it,v) \
  for (__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)

using namespace std;

int m, x, y, c[111], s[111];

int solve() {
  for (int i = 1; i <= m; i++) {
    int l = s[i-1];
    int r = s[m]-l;
    if (x <= l && l <= y && x <= r && r <= y)
      return i;
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> c[i];
    s[i] = c[i] + s[i-1];
  }

  cin >> x >> y;
  cout << solve() << '\n';

  return 0;
}

