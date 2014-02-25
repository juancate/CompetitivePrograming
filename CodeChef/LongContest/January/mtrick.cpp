#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

string s;
long long l[N], a, b, c;

long long mulmod(long long a, long long b, long long c) {
  long long x = 0, y = a % c;

  while(b > 0) {
    if(b & 1) x = (x + y) % c;
    y = (y << 1) % c;
    b >>= 1;
  }

  return x;
}

typedef long double ld;

inline long long mul(long long a, long long b, long long mod){
  ld c = ld(b) / ld(mod);
  long long k = a * c;
  long long res = (a * b - mod * k) % mod;
  while(res < 0) res += mod;
  while(res >= mod) res -= mod;
  return res;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
      cin >> l[i];

    cin >> a >> b >> c >> s;

    a %= c, b %= c;

    for (int i = 0; i < n; i++)
      l[i] %= c;

    for (int i = 0; i < n; i++) {

      if (s[i] == 'R') {
        int j = i, k = n-1;
        while (j < k)
          swap(l[j++], l[k--]);
      }
      else if (s[i] == 'A') {
        for (int j = i; j < n; j++)
          l[j] = (l[j] + a) % c;
      }
      else {
        for (int j = i; j < n; j++)
          l[j] = mul(l[j], b, c);
      }

      l[i] %= c;
      if (i) cout << ' ';
      cout << l[i];
    }
    cout << '\n';
  }

  return 0;
}
