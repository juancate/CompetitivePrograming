#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cassert>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <complex>

#define D(x) cerr << #x << " = " << (x) << endl;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

long long sieve_size;
bitset<100010> bs;
vector<int> primes;

void sieve(long long upperbound) {
  sieve_size = upperbound + 1;
  bs.set();
  bs[0] = bs[1] = 0;
  for(long long i = 2; i <= sieve_size; i++) {
    if(bs[i]) {
      for(long long j = i*i; j <= sieve_size; j += i)
        bs[j] = 0;
      primes.push_back((int)i);
    }
  }
}

bool is_prime(long long N) {
  if(N <= sieve_size) return bs[N];
  for(int i = 0; i < primes.size(); i++)
    if(N % primes[i] == 0) return false;
  return true;
}

char _s[512];

int to_number(int a, int b) {
  int n = 0;

  for(int i = a; i < b; i++) {
    n *= 10;
    n += _s[i] - '0';
  }

  return n;
}

int main() {
  sieve(100000);

  while(scanf("%s", _s)) {
    if(!strcmp(_s, "0")) break;
    int n = strlen(_s);

    int best = -1;

    for(int length = 7; length > 0; length--) {
      for(int i = 0; i+length <= n; i++) {
        int x = to_number(i, i+length);
        if(x <= 100000 && is_prime(x)) {
          best = max(best, x);
        }
      }
    }
    printf("%d\n", best);
  }

  return 0;
}

