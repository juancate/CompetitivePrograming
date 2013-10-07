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
      long long sum = 0;
      for (; idx; idx -= (idx & -idx))
        sum += t[idx];
      return sum;
    }

    int rsq(int a, int b) {
      return rsq(b) - (a == 1 ? 0 : rsq(a-1));
    }

    void adjust(int k, int v, int P) {
      for (; k <= n; k += (k & -k))
        t[k] = (t[k] + v) % P;
    }
};

int n;
long long B[maxn];

void precalculate(int b, int P) {
  B[n-1] = 1;
  for (int i = 1; i < n; i++)
    B[n-i-1] = (B[n-i] * b) % P;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int q, b, p;

  while (cin >> b >> p >> n >> q) {
    if ((b|p|n|q) == 0)
      break;

    BIT t(n);
    precalculate(b, p);
    cerr << "p = " << p << endl;

    while (q--) {
      char op;
      cin >> op;
      for (int i = 1; i < t.n; i++)
        cerr << t.t[i] << ' ';
      cerr << '\n';

      if (op == 'E') {
        int i, v;
        cin >> i >> v;
      }
      else {
        int i, j;
        cin >> i >> j;
        long long ans = (t.rsq(i, j) % p);
        cout << ans << '\n';
      }
    }
    cout << "-\n";
  }

  return 0;
}
