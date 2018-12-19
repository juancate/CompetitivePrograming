#include <bits/stdc++.h>

using namespace std;

const int INF = int(1e9);
const int N = 210;

int n, k, a[N], sum[N], z[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k;
  bool all_negative = true;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] > 0)
      all_negative = false;
  }

  if (all_negative) {
    sort(a, a+n);
    cout << a[n-1] << '\n';
    return 0;
  }

  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i-1];
    if (a[i-1] > 0)
      sum[i] += a[i-1];

    z[i] = z[i-1];
    if (a[i-1] <= 0)
      z[i]++;
  }

  int best = -INF;
  int l, r;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < i; j++) {
      int tot = z[i] - z[j];
      int curr = sum[i] - sum[j];

      l = j, r = i-1;
      vector<int> v;
      for (int s = 0; s < n; s++) {
        if (!(l <= s && s <= r))
          v.push_back(a[s]);
      }
      sort(v.rbegin(), v.rend());

      vector<int> w;
      for (int s = 0; s < n; s++) {
        if ((l <= s && s <= r))
          w.push_back(a[s]);
      }
      sort(w.begin(), w.end());

      int turns = k;
      for (int s = 0, p = 0; s < w.size() && p < v.size() && tot; s++, p++) {
        if (turns) {
          if (v[p] > w[s]) {
            curr += v[p];
            tot--;
            turns--;
          }
        }
      }

      best = max(best, curr);
    }
  }

  cout << best << '\n';

  return 0;
}

