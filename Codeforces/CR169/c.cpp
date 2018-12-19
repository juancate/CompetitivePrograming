#include <bits/stdc++.h>

using namespace std;

const int maxn = int(2e5)+10;

class BIT {
public:
  int t[maxn], n;
  BIT(int m) {
    n = ++m;
    fill(t, t+n, 0);
  }

  int rsq(int idx) {
    int sum = 0;
    for (; idx; idx -= (idx & -idx))
      sum += t[idx];
    return sum;
  }

  // not use with adjust range
  int rsq(int a, int b) {
    return rsq(b) - (a == 1 ? 0 : rsq(a-1));
  }

  void adjust(int k, int v) {
    for (; k <= n; k += (k & -k))
      t[k] += v;
  }

  void increment_at(int index) {
    adjust(index, 1);
  }

  void adjust_range(int a, int b, int v) {
    adjust(a, v);
    adjust(b+1, -v);
  }
};

int n, q, ql[maxn], qr[maxn];
long long a[maxn], b[maxn];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> q;

  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a+n);

  for (int i = 0; i < q; i++)
    cin >> ql[i] >> qr[i];

  BIT fenwick(n);

  for (int i = 0; i < q; i++)
    fenwick.adjust_range(ql[i], qr[i], 1);

  for (int i = 1; i <= n; i++)
    b[i-1] = fenwick.rsq(i);
  sort(b, b+n);

  long long ans = 0;
  for (int i = 0; i < n; i++)
    ans += a[i] * b[i];
  cout << ans << '\n';

  return 0;
}
