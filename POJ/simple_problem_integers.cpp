#include <algorithm>
#include <iostream>

using namespace std;

// http://poj.org/problem?id=3468
// WA

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
    while (at <= n) {
      dataMul[at] += mul;
      dataAdd[at] += add;
      at |= (at +  1);
    }
  }

  void update(int left, int right, long long by) {
    internalUpdate(left, by, -by * (left-1));
    internalUpdate(right, -by, by * right);
  }

  long long query(int at) {
    long long mul = 0, add = 0;
    int start = at;

    while(at > 0) {
      mul += dataMul[at];
      add += dataAdd[at];
      at = (at & (at + 1)) - 1;
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

  int n, q;
  while (cin >> n >> q) {
    BIT tree(n);

    for (int i = 1, v; i <= n; i++) {
      cin >> v;
      tree.update(i, i, v);
    }

    while (q--) {
      char op;
      int l, r;
      cin >> op >> l >> r;

      if (op == 'Q')
        cout << tree.query(l, r) << endl;
      else{
        int v;
        cin >> v;
        tree.update(l, r, v);
      }
    }
  }

  return 0;
}
