#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;

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
};

int a[maxn];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;

  while (cin >> n >> k) {
    BIT zeros(n), neg(n);

    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] < 0) neg.adjust(i, +1);
      if (a[i] == 0) zeros.adjust(i, +1);
    }

    string ans;

    while (k--) {
      char cmd;
      cin >> cmd;

      if (cmd == 'C') {
        int i, v;
        cin >> i >> v;

        if (v < 0) {
          if (a[i] >= 0) neg.adjust(i, +1);
          if (a[i] == 0) zeros.adjust(i, -1);
        }
        else if (v == 0) {
          if (a[i] < 0) neg.adjust(i, -1);
          if (a[i] != 0) zeros.adjust(i, +1);
        }
        else {
          if (a[i] < 0) neg.adjust(i, -1);
          if (a[i] == 0) zeros.adjust(i, -1);
        }

        a[i] = v;
      }
      else {
        int i, j, x, z;
        cin >> i >> j;

        x = neg.rsq(i, j);
        z = zeros.rsq(i, j);

        ans.push_back(z > 0? '0' : x & 1? '-' : '+');
      }
    }

    cout << ans << endl;
  }

  return 0;
}
