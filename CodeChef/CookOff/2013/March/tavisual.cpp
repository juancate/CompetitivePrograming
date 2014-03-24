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
  int t;
  scanf("%d", &t);

  while(t--) {
    int n, c, q, l, r, d;
    scanf("%d%d%d", &n, &c, &q);

    while(q--) {
      scanf("%d%d", &l, &r);
      if(l <= c && c <= r) {
        d = c - l;
        if(r - c < d) {
          d = r - c;
          c = l + d;
        }
        else {
          c = r - d;
        }
      }
    }
    printf("%d\n", c);
  }

  return 0;
}

