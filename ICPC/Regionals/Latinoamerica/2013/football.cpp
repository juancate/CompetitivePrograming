#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, g;
  while (cin >> n >> g) {
    vector<int> d;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int a, b;
      cin >> a >> b;

      if (a > b)
        ans += 3;
      else {
        if (g > 0) {
          if (a == b) {
            ans += 3;
            g--;
          }
          else {
            d.push_back(b-a);
          }
        }
        else {
          if (a == b)
            ans++;
        }
      }
    }
    sort(d.begin(), d.end());

    for (int i = 0; i < d.size() && g > 0; i++) {
      if (d[i] > g)
        break;
      if (g == d[i]) {
        ans++;
        g -= d[i];
      }
      else {
        ans += 3;
        g -= d[i]+1;
      }
    }
    cout << ans << '\n';
  }

  return 0;
}
