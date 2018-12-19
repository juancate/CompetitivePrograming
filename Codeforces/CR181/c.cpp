#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000001;
const int mod = int(1e9) + 7;

long long fact[maxn];

long long mod_pow(long long x, long long y) {
  long long r = 1, a = x;
  while(y > 0) {
    if(y & 1) r = (r * a) % mod;
    a = (a * a) % mod;
    y /= 2;
  }
  return r;
}

long long mod_inverse(long long x) {
  return mod_pow(x, mod-2);
}

long long mod_division(long long p, long long q) {
  return (p * mod_inverse(q)) % mod;
}

long long comb(long long n, int k) {
  long long res = fact[n];

  res = mod_division(res, fact[n-k]);
  res = mod_division(res, fact[k]);

  return res;
}


bool excellent(int val, int a, int b) {
  while(val > 0) {
    int r = val % 10;
    if(r != a && r != b)
      return false;
    val /= 10;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);

  fact[0] = 1;
  for(long long i = 1; i < maxn; i++)
    fact[i] = (i * fact[i-1]) % mod;

  int a, b, n;
  cin >> a >> b >> n;

  long long ans = 0;

  for(int i = 0; i <= n; i++) {
    int x = a*i + b*(n-i);

    if(excellent(x, a, b)) {
      ans += comb(n, i);
      ans %= mod;
    }
  }

  cout << ans << endl;

  return 0;
}
