#include <bits/stdc++.h>

using namespace std;

long long a[100010];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, d;
  cin >> n >> d;

  for (int i = 0; i < n; i++)
    cin >> a[i];

  long long ans = 0;

  for (int i = 0; i < n; i++) {
    int j = lower_bound(a,a+n,a[i]+d) - a;
    if (j >= n || a[j] > a[i]+d)
      j--;
    long long k = j-i-1;
    ans += (k * (k+1)) >> 1;
  }

  cout << ans << '\n';

  return 0;
}
