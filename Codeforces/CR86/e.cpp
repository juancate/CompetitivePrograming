#include <bits/stdc++.h>

using namespace std;

// Algorithm: Number theory

const int MAX = 300000010;

int flag[MAX>>6];
int n, primes[9000000];

#define ifc(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x) (flag[x>>6]|=(1<<((x>>1)&31)))

void sieve() {
  int i, j, k;
  n = 0;
  primes[n++] = 2;
  for (i = 3; i*i < MAX; i += 2)
    if (!ifc(i)) {
      for (j = i*i,k = i<<1; j < MAX; j += k)
        isc(j);
    }
  for (i = 5; i < MAX; i += 4)
    if (!ifc(i)) {
      if ((i & 1) && ((i-1) % 4 == 0)) // fermat's theorem
        primes[n++] = i;
    }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  sieve();

  int l, r;
  cin >> l >> r;

  int i = lower_bound(primes, primes+n, l) - primes;
  int j = upper_bound(primes, primes+n, r) - primes;

  cout << j-i << '\n';

  return 0;
}
