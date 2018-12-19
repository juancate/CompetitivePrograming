#include <bits/stdc++.h>

using namespace std;

int n;
char s[111][111];
bool r[111], c[111];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    for (int j = 0; j < n; j++)
      if (s[i][j] != 'E')
        r[i] = c[j] = 1;
  }

  int cnt = 0;
  for (int i = 0; i < n; i++)
    cnt += r[i];

  if (cnt == n) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (s[i][j] != 'E') {
          cout << (i+1) << " " << (j+1) << endl;
          break;
        }
  }
  else {
    cnt = 0;
    for (int j = 0; j < n; j++)
      cnt += c[j];

    if (cnt == n) {
      for (int j = 0; j < n; j++)
        for (int i = 0; i < n; i++)
          if (s[i][j] != 'E') {
            cout << (i+1) << " " << (j+1) << endl;
            break;
          }
    }
    else cout << -1 << endl;
  }

  return 0;
}
