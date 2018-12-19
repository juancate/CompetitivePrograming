#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, q;
long long a[N], sum[N];

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> n >> q) {
    for (int i = 0; i < n; i++)
      cin >> a[i];

    memset(sum, 0, sizeof sum);
    for (int i = 1; i < n; i++)
      sum[i] = a[i] + sum[i-1];

    while (q--) {
      long long k;
      cin >> k;

      int pos = lower_bound(sum, sum+n, k) - sum;
      cout << pos;
      if (q) cout << ' ';
    }
    cout << '\n';
  }

  return 0;
}
