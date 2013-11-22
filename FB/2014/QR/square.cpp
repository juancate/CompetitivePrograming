#include <bits/stdc++.h>

using namespace std;

int n;
string a[20];

bool solve() {
  int l, r, row;
  for (int i = 0; i < n; i++) {
    l = -1;
    for (int j = 0; j < n; j++)
      if (a[i][j] == '#') {
        l = j;
        break;
      }
    if (l != -1) {
      row = i;
      r = l;
      for (; r < n-1; r++)
        if (a[i][r+1] != '#')
          break;
      break;
    }
  }

  int sz = r-l+1;
  if (row+sz > n)
    return false;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == '#') {
        if (!(row <= i && i < row+sz && l <= j && j <= r))
          return false;
      }
      if (a[i][j] == '.') {
        if (row <= i && i < row+sz && l <= j && j <= r)
          return false;
      }
    }
  }

  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> a[i];

    cout << "Case #" << tc << ": ";
    cout << (solve()? "YES" : "NO") << '\n';
  }

  return 0;
}
