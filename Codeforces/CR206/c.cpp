#include <bits/stdc++.h>

#define foreach(it,v) \
  for (__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)

using namespace std;

const int maxn = 100010;

int a[maxn], q[2]; //ql, qr
long long sum[maxn];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, l, r;
  cin >> n >> l >> r >> q[0] >> q[1];

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum[i] = a[i];
    if (i) sum[i] += sum[i-1];
  }

  long long ans = 0;

  int pl = 0, pr = n-1;

  while (pl <= pr) {
    if (pl == pr) {
      ans += min(a[pl]*l, a[pr]*r);
      break;
    }

    long long sump = sum[pr];
    sump -= (pl > 0)? sum[pl-1] : 0;
    long long suml = sump;
    sump *= l;
    sump += (pr - pl) * q[0];

    if (sump <= a[pr] * r + a[pl] * l) {
      ans += sump;
      pl = pr+1;
    }
    else {
      suml *= r;
      suml += (pr - pl) * q[1];
      if (suml <= a[pl] * l + a[pr] * r) {
        ans += suml;
        pr = pl-1;
      }
      else {
        ans += a[pl] * l;
        ans += a[pr] * r;
        pl++, pr--;
      }
    }
  }

  cout << ans << '\n';

  return 0;
}

