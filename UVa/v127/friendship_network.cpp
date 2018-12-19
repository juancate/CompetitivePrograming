#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n, d[N];
bool g[N][N];

bool can() {
  for (int i = 0; i < n; i++) {
    if (d[i]) {
      for (int j = 0; j < n && d[i]; j++) {
        if (g[i][j] == 0 && i != j && d[j]) {
          g[i][j] = g[j][i] = 1;
          d[i]--;
          d[j]--;
        }
      }
    }
    if (d[i]) return false;
  }
  return true;
}

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> n) {
    for (int i = 0; i < n; i++) {
      cin >> d[i];
      for (int j = 0; j < n; j++)
        g[i][j] = 0;
    }
    sort(d, d+n);
    reverse(d, d+n);
    for (int i = 0; i < n; i++) cout << d[i] << ' ';
    cout << '\n';
    cout << can() << '\n';
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++)
        cout << g[i][j] << ' ';
      cout << '\n';
    }
  }

  return 0;
}
