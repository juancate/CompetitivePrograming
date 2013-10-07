#include <bits/stdc++.h>

using namespace std;

const int maxn = 200010;

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

int a[maxn];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    map<int, int> M;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      M[a[i]] = i+1;
    }
    sort(a, a+n);

    BIT tree(n);

    long long ans = 0;
    for (int i = 0; i < n; i++) {
      int pos = M[a[i]];
      ans += tree.rsq(pos+1, n);
      tree.adjust(pos, 1);
    }

    cout << ans << '\n';
  }

  return 0;
}
