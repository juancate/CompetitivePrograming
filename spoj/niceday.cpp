#include <bits/stdc++.h>

using namespace std;

const int maxn = int(1e5)+10;

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

int b[maxn];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    int ans = 0;
    for (int i = 0; i < n; i++) {
      int cnt = 0;
      for (int j = 0; j < 3; j++) {
        int v;
        cin >> v;
        if (v == 1)
          cnt++;
      }
      ans = max(ans, cnt);
    }
    if (ans == 1) cout << 3 << '\n';
    else if (ans == 2) cout << 0 << '\n';
    else cout << 1 << '\n';
  }

  return 0;
}
