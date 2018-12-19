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
const int maxn = 1010;

long long m[maxn], others[maxn];

long long mod_mul(long long a, long long b, long long c) {
  long long x = 0, y = a%c;

  while(b > 0) {
    if(b & 1) x = (x + y) % c;
    y = (y << 1) % c;
    b >>= 1;
  }
  return x;
}

long long mod_pow(long long a, long long b, long long c) {
  long long x = 1, y = a;

  while(b > 0) {
    if(b & 1) x = mod_mul(x, y, c);
    y = mod_mul(y, y, c);
    b >>= 1;
  }

  return x;
}

int main() {
  int t;
  scanf("%d", &t);

  while(t--) {
    int n, k;
    scanf("%d%d", &n, &k);

    long long ans = mod_pow(k, n-1, mod);
    m[1] = 0; others[1] = k;
    for(int i = 2; i < n; i++) {
      m[i] = others[i-1];
      others[i] = (mod_mul(others[i-1], (k-1), mod) + mod_mul(m[i-1], k, mod)) % mod;
    }
    ans = (ans - m[n-1] + mod) % mod;
    printf("%lld\n", ans);
  }

  return 0;
}

