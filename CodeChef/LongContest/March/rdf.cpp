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

double p[100001];

int main() {
  int t, n, k;
  scanf("%d", &t);
  p[0] = p[1] = 0;
  p[2] = 0.5;
  for(int i = 3; i < 100000; i++) {
    p[i] = p[i-1] / i;
  }

  while(t--) {
    scanf("%d%d", &n, &k);
    //for(int i = 0; i <= n; i++)
    //    fprintf(stderr, "%lf ", p[i]);
    //fprintf(stderr, "\n");
    if(k >= n) puts("0");
    else if(k == 1) {
        int64 x = n * (n-1) / 2;
        double ans = (double)x / (double)n;
        printf("%.20lf\n", ans);
    }
    else if(k == n-1)
        printf("%.200lf\n", p[n]);
    else
        puts("Good Luck! :P");
  }

  return 0;
}

