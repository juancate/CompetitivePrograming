#include <bits/stdc++.h>

using namespace std;

int n, sum, a[33], b[33], ans[33];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> sum;

  int sum_min = 0, sum_max = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    sum_min += a[i];
    sum_max += b[i];
  }

  if (sum_min <= sum && sum <= sum_max) {
    int curr_sum = 0;
    for (int i = 0; i < n; i++) {
      ans[i] = a[i];
      curr_sum += a[i];
    }

    if (curr_sum < sum) {
      int diff = sum - curr_sum;
      for (int i = 0; i < n; i++) {
        int delta = min(b[i]-ans[i], diff);
        ans[i] += delta;
        diff -= delta;
        if (diff == 0)
          break;
      }
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++)
      cout << ans[i] << ' ';
    cout << '\n';
  }
  else
    cout << "NO\n";

  return 0;
}
