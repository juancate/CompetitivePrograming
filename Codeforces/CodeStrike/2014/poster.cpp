#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  cin >> n >> k;

  string s;
  cin >> s;

  int l = k-1, r = n-k;

  if (l < r) {
    while (k > 1) {
      cout << "LEFT\n";
      k--;
    }
    while (k <= n) {
      cout << "PRINT " << s[k-1] << '\n';
      if (k < n)
        cout << "RIGHT\n";
      k++;
    }
  }
  else {
    while (k < n) {
      cout << "RIGHT\n";
      k++;
    }
    while (k >= 1) {
      cout << "PRINT " << s[k-1] << '\n';
      if (k > 1)
        cout << "LEFT\n";
      k--;
    }
  }

  return 0;
}
