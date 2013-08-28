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

    int rsq(int idx, int p) {
      int sum = 0;
      for (; idx; idx -= (idx & -idx))
        sum = (sum + t[idx]) % p;
      return sum % p;
    }

    int rsq(int a, int b, int p) {
      return rsq(b, p) - (a == 1 ? 0 : rsq(a-1, p));
    }

    void adjust(int k, int v, int P) {
      for (; k <= n; k += (k & -k))
        t[k] = (t[k] + v) % P;
    }
};

int n;
long long B[maxn], invB[maxn];

void precalculate(int b, int P) {
  B[n-1] = invB[n-1] = 1;
  for (int i = 1; i < n; i++) {
    B[n-i-1] = (B[n-i] * b) % P;
    invB[n-i-1] = (invB[n-i] * b) % (P-2);
    cerr << "B[" << n-i-1 << "] = " << B[n-i-1] << " ";
    cerr << "invB[" << n-i-1 << "] = " << invB[n-i-1] << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int q, b, p;

  while (cin >> b >> p >> n >> q) {
    if ((b|p|n|q) == 0)
      break;

    BIT t(n);
    precalculate(b,p);
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
        t.adjust(i, ((B[i-1] * v) % p)-t.rsq(i,i,p)+p, p);
      }
      else {
        int i, j;
        cin >> i >> j;
        long long ans = (t.rsq(i, j) % p);
        cerr << " >> ans = " << ans << " invB = " << invB[j-1] << '\n';
        ans = (ans * invB[j-1]) % p;
        cout << ans << '\n';
      }
    }
    cout << "-\n";
  }

  return 0;
}
