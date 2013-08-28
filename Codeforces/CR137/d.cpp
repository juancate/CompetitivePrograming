#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;

int n, x, a[maxn], b[maxn];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> x;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a+n);
  reverse(a,a+n);
  for (int i = 0; i < n; i++)
    cin >> b[i];
  sort(b, b+n);
  reverse(b,b+n);

  int ans = 0;

  for (int i = 0, j = n-1; i < n; i++) {
    while (j >= 0 && a[i]+b[j] < x) j--;
    if (j >= 0) {
      ans++;
      j--;
    }
  }

  cout << 1 << ' ' << ans << '\n';

  return 0;
}
