#include <bits/stdc++.h>

#define foreach(it,v) \
  for (__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)

using namespace std;

const int maxn = 300010;

long long sieve_size;
bitset<maxn> bs;
vector<int> primes;

void sieve(long long up) {
  sieve_size = up+1;

  bs.set();
  bs[0] = bs[1] = 0;
  for (long long i = 2; i <= sieve_size; i++) if (bs[i]) {
    for (long long j = i*i; j <= sieve_size; j += i)
      bs[j] = 0;
    primes.push_back(i);
  }
}

int n, k, a[maxn];

bool check(int x) {
  for (int i = 0; i < n; i++)
    if (a[i] % x > k)
      return false;
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  sieve(300000);

  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  sort(a, a+n);

  int limit = max(1, a[0]-k);
  int ans = 1;
  for (int i = 0; i < primes.size(); i++) {
    if (check(primes[i])) {
      ans = primes[i];
      break;
    }
  }

  int g = 0;
  cerr << "ans => " << ans << '\n';
  for (int i = 0; i < n; i++) {
    a[i] = ans * (a[i] / ans);
    cerr << a[i] << ' ';
    g = __gcd(g, a[i]);
  }
  cerr << '\n';

  cout << g << '\n';

  return 0;
}

