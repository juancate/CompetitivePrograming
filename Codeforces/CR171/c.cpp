#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;
int a[maxn], inc[maxn], _dec[maxn];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  inc[0] = _dec[0] = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i+1];
    if (i == 0) inc[i+1] = _dec[i+1] = 0;
    else {
      inc[i+1] = inc[i] + (a[i+1] > a[i]);
      _dec[i+1] = _dec[i] + (a[i+1] < a[i]);
    }
  }

  while (m--) {
    int l, r;
    cin >> l >> r;

    int curr_inc = inc[r] - inc[l-1];
    int curr_dec = _dec[r] - _dec[l-1];

    if (curr_inc + curr_dec <= 2)
      cout << "Yes\n";
    else
      cout << "No\n";
  }

  return 0;
}
