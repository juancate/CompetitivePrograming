#include <bits/stdc++.h>

using namespace std;

long long sieve_size;
bitset<2000010> bs;
vector<int> primes;

void sieve(long long up) {
  sieve_size = up+1;
  bs.set();
  bs[0] = bs[1] = 0;

  for (long long i = 2; i <= sieve_size; i++) if (bs[i]) {
    for (long long j = i*i; j <= sieve_size; j+=i)
      bs[j] = 0;
    primes.push_back(i);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  sieve(2000000);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    if (i) cout << ' ';
    cout << primes[i];
  }
  cout << endl;

  return 0;
}

