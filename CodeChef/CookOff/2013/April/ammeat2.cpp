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
    int n, k;
    scanf("%d%d", &n, &k);

    if(k == 1)
      printf("%d\n", n);
    else if(k > n/2)
      printf("-1\n");
    else {
      for(int i = 1; i <= k; i++) {
        if(i-1) printf(" ");
        printf("%d", i<<1);
      }
      printf("\n");
    }
  }

  return 0;
}

