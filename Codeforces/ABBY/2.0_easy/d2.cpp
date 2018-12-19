#include <bits/stdc++.h>

using namespace std;

const int maxn = 1010;

int n, m, c, a[maxn], b[maxn], sum[maxn];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m >> c;

  for (int i = 0; i < n; i++)
    cin >> a[i];

  for (int i = 0; i < m; i++) {
    cin >> b[i];
    sum[i] = b[i];
    if (i) sum[i] = (sum[i-1] + sum[i]) % c;
  }

  for (int i = 0; i < m; i++)
    a[i] = (a[i] + b[i]) % c;

  for (int i = 0; i < n; i++) {
    if (i) cout << ' ';
    cout << a[i];
  }
  cout << '\n';

  return 0;
}
