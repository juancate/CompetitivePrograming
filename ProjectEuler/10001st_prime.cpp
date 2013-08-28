#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

long long sieve_size;
bitset<10000010> bs;
vector<long long> primes;

void sieve(long long upp) {
  sieve_size = upp;
  bs.set();
  bs[0] = bs[1] = 0;
  for(long long i = 2; i <= sieve_size; i++) if(bs[i]) {
    for(long long j = i*i; j <= sieve_size; j += i)
      bs[j] = 0;
    primes.push_back(i);
  }
}

int main() {
  sieve(10000000);

  cout << primes.size() << endl;
  cout << primes[10000] << endl;
  return 0;
}
