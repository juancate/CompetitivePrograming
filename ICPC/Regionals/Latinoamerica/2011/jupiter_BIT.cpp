#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;

class BIT {
public:
  long long t[maxn], n;
  BIT(int m) {
    n = ++m;
    fill(t, t+n, 0);
  }

  int rsq(int idx, int P) {
    long long sum = 0;
    for (; idx; idx -= (idx & -idx))
      sum = (sum + t[idx] % P) % P;
    return sum;
  }

  int rsq(int a, int b, int P) {
    return (rsq(b, P) - rsq(a - 1, P) + P) % P;
  }

  void adjust(int k, long long v, int P) {
    for (; k <= n; k += (k & -k))
      t[k] = (t[k] + v) % P;
  }
  void update(int k, long long v, int P) {
    int x = rsq(k, k, P);
    adjust(k, v - x, P);
  }
};

int n;

int mod_pow(int a, int b, int p) {
  long long x = a, r = 1;
  while (b > 0) {
    if (b & 1) r = (r * x) % p;
    x = (x * x) % p;
    b >>= 1;
  }
  return r;
}

long long x ,y, d;

void extended_euclid(long long a, long long b) {
  if (b == 0) {
    x = 1, y = 0, d = a;
    return;
  }
  extended_euclid(b, a % b);
  long long x1 = y;
  long long y1 = x - (a / b) * y;
  x = x1;
  y = y1;
}

long long inverse(long long a, long long p) {
  extended_euclid(a, p);
  return x;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int q, b, p;

  while (cin >> b >> p >> n >> q) {
    if ((b|p|n|q) == 0)
      break;

    BIT tree(n);

    while (q--) {
      char op;
      cin >> op;

      if (op == 'E') {
        long long i, v;
        cin >> i >> v;
        tree.update(i, v * mod_pow(b, n-i, p), p);
      }
      else {
        int i, j;
        cin >> i >> j;
        long long ans = tree.rsq(i, j, p);
        long long base = mod_pow(b, n-j, p);

        ans = (ans * inverse(base, p)) % p;
        ans += p;

        cout << (ans % p) << '\n';
      }
    }
    cout << "-\n";
  }

  return 0;
}
