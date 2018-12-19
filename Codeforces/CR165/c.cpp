#include <bits/stdc++.h>

using namespace std;

const int maxn = int(1e5)+10;

int n, a[maxn], k[maxn];

double log4(double x) {
  return log(x) / log(4);
}

bool can(int i, int p) {
  return (int)ceil(log4(a[i])) + k[i] < p;
}

int solve(int i) {
  int lo = 0, hi = int(2e9);

  while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (can(i,mid)) hi = mid;
    else lo = mid+1;
  }
  return lo;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  int bestk = 0;
  for (int i = 0; i < n; i++) {
    cin >> k[i] >> a[i];
    bestk = max(k[i], bestk);
  }

  int ans = 0;
  for (int i = 0; i < n; i++)
    ans = max(ans, solve(i));

  if (ans-1 != bestk)
    cout << ans-1 << '\n';
  else
    cout << ans << '\n';

  return 0;
}
