#include <bits/stdc++.h>

using namespace std;

char a[11][11];
bool s[11][11];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int ans = 0;
  memset(s, 0, sizeof(s));
  for (int i = 0; i < n; i++) {
    int curr = 0;
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'S') {
        curr = 0;
        for (int k = 0; k < m; k++)
          s[i][k] = 0;
        break;
      }
      else {
        curr += !s[i][j]; s[i][j] = 1;
      }
    }
    ans += curr;
  }

  for (int i = 0; i < m; i++) {
    int curr = 0;
    for (int j = 0; j < n; j++) {
      if (a[j][i] == 'S') {
        curr = 0;
        break;
      }
      else {
        curr += !s[j][i]; s[j][i] = 1;
      }
    }
    ans += curr;
  }

  cout << ans << endl;

  return 0;
}
