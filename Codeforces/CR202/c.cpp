#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;

int a[maxn];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  long long max = -int(1e9), sum = 0;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    max = std::max(max, (long long)a[i]);
  }

  long long ans = std::max(max, (long long)ceil(sum / double(n - 1)));
  cout << ans << '\n';

  return 0;
}
