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

vector<int> d, f;
vector<int> cnt;

void factor(int cf, int pp) {
  if(cf == d.size()) {
    f.push_back(pp);
    return;
  }
  for(int i = 0, r = 1; i <= cnt[cf]; r *= d[cf], i++)
    factor(cf+1, pp*r);
}

void solve(long long x, int& l, int& r) {
  long long q = x;
  long long p = 2LL;

  d.clear();
  cnt.clear();
  //d.push_back(1LL);

  while(p * p <= q) {
    if(q % p == 0) {
      int c = 0;
      while(q % p == 0) {
        d.push_back(p);
        c++;
        q /= p;
      }
      d.push_back(p);
      cnt.push_back(c);
    }
    p++;
  }

  if(q > 1) {
    d.push_back(q);
    cnt.push_back(1);
  }

  f.clear();
  factor(0,1);

  for(int i = 0; i < f.size(); i++) {
    long long A, B, v, u, n, m;
    A = d[i]; B = 2LL*x / f[i];
    v = A+B; u = B-A;
    n = (-1 + (int)sqrt(8*x + u*u)) / 2;
    m = (-1 + (int)sqrt(1 - 8*x + 4*n*n + 4*n)) / 2;
    //assert((8*x + u*u) >= 0);
    //assert((1 - 8*x + 4*n*n + 4*n) >= 0);

    D(n); D(m);

    if(n-m+1 > r-l+1) {
      l = m;
      r = n;
    }
  }
}

int main() {
  long long n;

  while(scanf("%lld", &n)) {
    if(n < 0) break;
    int l = 0, r = 0;
    solve(n, l, r);
    printf("%lld = %d + ... + %d\n", n, l+1, r);
  }

  return 0;
}

