#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;

int n, k, v[maxn], a[maxn];

void solve() {
  int l = -1, r = -1;
  for (int i = 1, j = n; i <= n; i++) {
    while (j > 0 && a[j] - a[i-1] >= k) j--;
    if (j > 0 && a[j+1]-a[i-1] == k) {
      l = i, r = j+1;
    }
  }

  if (l > 0 && r > 0) {
    while (l+1 <= r && a[l] == a[l+1]) l++;
    while (r-1 >= l && a[r] == a[r-1]) r--;
  }

  cout << l << ' ' << r << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k;

  set<int> seen;
  memset(a, 0, sizeof(a));
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    if (!seen.count(v[i]))
      a[i+1]++;
    a[i+1] += a[i];
    seen.insert(v[i]);
  }

  solve();

  return 0;
}

