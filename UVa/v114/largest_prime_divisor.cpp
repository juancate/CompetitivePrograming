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
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

// Algorithm: Number theory - Finding prime factors

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

int64 solve(int64 q) {
  int64 p = 2;
  int64 ans = 1;
  int64 cnt = 0;

  while(p <= q / p) {
    if(q % p == 0) {
      while(q % p == 0) {
	q /= p;
      }
      ans = max(ans, p);
      cnt++;
    }
    p++;
  }

  if(q > 1) {
    ans = max(q, ans);
    cnt++;
  }

  if(cnt < 2) return -1;

  return ans;
}

int main() {
  int64 n;
  while(scanf("%lld", &n)) {
    if(n == 0) break;

    if(n < 0) n = -n;

    printf("%lld\n", solve(n));
  }
}

