#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> g[10000];

int accum_difference(int T) {
  int diff = 0;

  for (int i = 0; i < n; i++) {
    int pos = lower_bound(g[i].begin(), g[i].end(), T) - g[i].begin();
    int m = g[i].size();
    diff += abs(pos - (m - pos));
  }

  return diff;
}

int solve() {
  int l = 0, r = 1001;
  int ans = int(1e9);
  for (int i = l; i < r; i++)
    ans = min(ans, accum_difference(i));

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> n) {
    if (n == 0)
      break;

    for (int i = 0, k; i < n; i++) {
      cin >> k;
      g[i].clear();
      for (int j = 0, a; j < k; j++) {
        cin >> a;
        g[i].push_back(a);
      }
      sort(g[i].begin(), g[i].end());
    }

    cout << solve() << '\n';
  }

  return 0;
}

