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

long long p[10];

int main() {
  int t;
  scanf("%d", &t);

  while(t--) {
    int n;
    long long m;
    scanf("%d%lld", &n, &m);

    for(int i = 0; i < n; i++)
      scanf("%lld", p+i);

    int best = INF;
    for(int subset = 1; subset < (1<<n); subset++) {
      long long sum = 0;
      for(int j = 0; j < n; j++)
        if(subset & (1<<j))
          sum += p[j];

      if(sum >= m)
        best = min(best, __builtin_popcount(subset));
    }
    if(best == INF) printf("-1\n");
    else printf("%d\n", best);
  }

  return 0;
}

