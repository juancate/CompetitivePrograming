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


int main() {
  int T;
  scanf("%d", &T);

  for(int run = 1; run <= T; run++) {
    long long r, t, a;
    scanf("%lld%lld", &r, &t);

    int lo = 0, hi = int(1e9);

    while(lo < hi) {
      int mid = lo + (hi-lo) / 2;
      a = 2LL*mid*mid + 2LL*r*mid + 3LL*mid + 2LL*r + 1LL;

      if(a > t) hi = mid;
      else lo = mid+1;
    }

    printf("Case #%d: %d\n", run, lo);
  }

  return 0;
}

