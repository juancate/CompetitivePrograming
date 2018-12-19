#include <bits/stdc++.h>

#define LSOne(x) ((x) & -(x))

using namespace std;

const int maxn = 100010;

class BIT {
public:
  long long dataMul[maxn], dataAdd[maxn];
  int n;
  BIT(int m) {
    n = ++m;
    fill(dataMul, dataMul+n, 0);
    fill(dataAdd, dataAdd+n, 0);
  }

  void internalUpdate(int at, long long mul, long long add) {
    for (; at <= n; at += LSOne(at)) {
      dataMul[at] += mul;
      dataAdd[at] += add;
    }
  }

  void update(int left, int right, long long by) {
    internalUpdate(left, by, -by * (left - 1));
    internalUpdate(right + 1, -by, by * right);
  }

  long long query(int at) {
    long long mul = 0, add = 0;
    int start = at;

    for (; at > 0; at -= LSOne(at)) {
      mul += dataMul[at];
      add += dataAdd[at];
    }

    return mul * start + add;
  }

  long long query(int a, int b) {
    return query(b) - (a <= 1? 0 : query(a-1));
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    int n, q;
    cin >> n >> q;

    BIT tree(n);

    while (q--) {
      int op, l, r, v;
      cin >> op >> l >> r;

      if (op == 0) {
        cin >> v;
        tree.update(l, r, v);
      }
      else {
        cout << tree.query(l, r) << '\n';
      }
    }
  }

  return 0;
}

