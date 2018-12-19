#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  for (int tc = 1; tc <= t; tc++) {
    int a, b, k;
    cin >> a >> b >> k;

    long long ans = 0;
    for (int i = 0; i < a; i++) {
      for (int j = 0; j < b; j++) {
        int curr = i & j;
        if (curr < k)
          ans++;
      }
    }

    cout << "Case #" << tc << ": ";
    cout << ans << '\n';
  }

  return 0;
}
