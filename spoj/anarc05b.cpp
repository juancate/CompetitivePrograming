#include <bits/stdc++.h>

using namespace std;

// http://www.spoj.com/problems/ANARC05B/
// DP

const int maxn = 100010;

int n, m, a[maxn], b[maxn];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> n) {
    if (n == 0)
      break;
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    cin >> m;
    for (int i = 1; i <= m; i++)
      cin >> b[i];

    for (int i = 0, j = 0; i <= n || j <= m;) {
      if (i <= n && j <= m && a[i] == b[j]) {
        a[i] += a[i-1];
        b[j] += b[j-1];
        a[i] = b[j] = max(a[i], b[j]);
        i++, j++;
      }
      else {
        if (i > n) {
          b[j] += b[j-1];
          j++;
        }
        else if (j > n) {
          a[i] += a[i-1];
          i++;
        }
        else if (a[i] < b[j]) {
          a[i] += a[i-1];
          i++;
        }
        else if (a[i] > b[j]) {
          b[j] += b[j-1];
          j++;
        }
      }
    }
    cout << max(a[n], b[m]) << '\n';
  }

  return 0;
}
