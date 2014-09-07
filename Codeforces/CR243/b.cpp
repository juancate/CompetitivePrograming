#include <bits/stdc++.h>

using namespace std;

int n, m, a[110][110];

bool equal_row(int i, int k) {
  for (int j = 0; j < m; j++)
    if (a[i][j] != a[k][j])
      return false;
  return true;
}

bool can(int from, int mid, int end) {
  int i = mid-1, k = mid;
  while (i >= 0 && k < end) {
    if (!equal_row(i, k))
      return false;
    i--, k++;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> a[i][j];

  if (n & 1)
    cout << n << '\n';
  else {
    int ans = n;
    int end = n;

    while (ans % 2 == 0) {
      int mid = ans / 2;
      if (!can(0, mid, end) || mid == 0)
        break;
      ans = mid;
      end = mid;
    }

    cout << ans << '\n';
  }

  return 0;
}

