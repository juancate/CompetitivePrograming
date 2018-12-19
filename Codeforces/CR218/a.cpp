#include <bits/stdc++.h>

using namespace std;

const int N = 111;

int a[N][N], cnt[3];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  cin >> n >> k;

  int rows = n / k;
  int cols = k;

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
      cin >> a[i][j];

  int ans = 0;
  for (int j = 0; j < cols; j++) {
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < rows; i++)
      cnt[a[i][j]]++;
    ans += min(cnt[1], cnt[2]);
  }
  cout << ans << '\n';

  return 0;
}
