#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;
const int mod = int(1e9) + 7;

char a[maxn];

long long pow(long long a, long long b, long long c = mod) {
  long long x = 1, y = a;

  while (b > 0) {
    if (b & 1) x = x*y%c;
    y = y*y%c;
    b >>= 1;
  }

  return x;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long long k;

  cin >> a >> k;
  int n = strlen(a);

  long long ans = 0;
  long long pn = pow(2,n,mod);
  long long b = (pow(pn,k,mod)-1+mod)%mod;
  long long q = pow((pn-1+mod)%mod, mod-2, mod);
  long long div = (b * q) % mod;

  for (int i = 0; i < n; i++) {
    if (a[i] == '0' || a[i] == '5') {
      ans = (ans + (pow(2,i,mod) * div) % mod) % mod;
    }
  }

  cout << ans << '\n';

  return 0;
}
