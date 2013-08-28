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

int a[111];

int main() {
  int t;
  scanf("%d", &t);

  while(t--) {
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++)
      scanf("%d", a+i);

    sort(a, a+n);

    int f = accumulate(a, a+k, 0);
    int s = accumulate(a+k, a+n, 0);

    int d1 = abs(f-s);
    f = accumulate(a, a+n-k, 0);
    s = accumulate(a+n-k, a+n, 0);

    int d2 = abs(f-s);
    printf("%d\n", max(d1, d2));
  }

  return 0;
}

