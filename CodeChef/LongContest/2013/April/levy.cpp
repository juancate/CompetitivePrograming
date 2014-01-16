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
bitset<10010> bs;
vector<int> primes;

void sieve(int upper) {
  sieve_size = upper+1;
  bs.set();
  bs[0] = bs[1] = 0;

  for(long long i = 2; i <= sieve_size; i++) if(bs[i]) {
    for(long long j = i*i; j <= sieve_size; j += i)
      bs[j] = 0;
    primes.push_back(i);
  }
}

int main() {
  sieve(10000);

  int t;
  scanf("%d", &t);

  while(t--) {
    int n;
    scanf("%d", &n);

    int ans = 0;
    for(int i = 0; i < primes.size(); i++) {
      int p = primes[i];
      int q = n - 2*p;
      if(q < 0) break;
      if(q >= 0 && bs[q])
        ans++;
    }
    printf("%d\n", ans);
  }

  return 0;
}

