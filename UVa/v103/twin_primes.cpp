#include <bits/stdc++.h>

using namespace std;

long long sieve_size;
bitset<20000010> bs;
vector<int> primes;
vector< pair<int,int> > twins;

void sieve(long long upp) {
  sieve_size = upp + 1;
  bs.set();
  bs[0] = bs[1] = 0;

  for(long long i = 2; i <= sieve_size; i++) if(bs[i]) {
    for(long long j = i*i; j <= sieve_size; j+=i)
      bs[j] = 0;
    primes.push_back(i);
  }
}

int main() {
  sieve(20000000);

  for(int i = 0; i < primes.size()-1; i++)
    if(primes[i+1] == primes[i]+2)
      twins.push_back(make_pair(primes[i], primes[i+1]));

  int s;
  while(~scanf("%d", &s)) {
    printf("(%d, %d)\n", twins[s-1].first, twins[s-1].second);
  }

  return 0;
}
