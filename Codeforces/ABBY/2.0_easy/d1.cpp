#include <bits/stdc++.h>

using namespace std;

const int maxn = 1010;

int n, m, c, a[maxn], b[maxn];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m >> c;

  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < m; i++)
    cin >> b[i];

  for (int step = 0; step < n-m+1; step++) {
    for (int i = step, j = 0; j < m; i++, j++)
      a[i] = (a[i] + b[j]) % c;
  }

  for (int i = 0; i < n; i++) {
    if (i) cout << ' ';
    cout << a[i];
  }
  cout << '\n';

  return 0;
}
