#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  int nn = n * n;

  int ans = 0;

  for (int a = 1; a <= n; a++) {
    for (int b = a; b <= n; b++) {
      int c = sqrt(a*a + b*b);
      if (c*c == a*a + b*b && c <= n)
        ans++;
    }
  }

  cout << ans << '\n';

  return 0;
}
