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

const int mod = INF+7;

long long mod_pow(long long x, long long p, int mod) {
  long long ans = 1;

  while(p > 0) {
    if(p & 1) ans = (ans * x) % mod;
    x = (x * x) % mod;
    p >>= 1;
  }

  return ans;
}

long long mod_inverse(long long x) {
  return mod_pow(x, mod-2, mod);
}

long long mod_division(long long p, long long q) {
  return (p * mod_inverse(q)) % mod;
}


int main() {
  int t;
  scanf("%d", &t);

  while(t--) {
    long long n;
    scanf("%lld", &n);
    int p = (n+1) / 2;

    long long ans = (26 - mod_pow(26, p+1, mod)) % mod;
    ans = mod_division(ans, 1 - 26);

    if(n & 1) p--;
    long long two = (26 - mod_pow(26, p+1, mod)) % mod;
    two = mod_division(two, 1 - 26);

    ans = (ans + two) % mod;
    printf("%lld\n", ans);
  }

  return 0;
}

