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

const int maxn = 21;

int dp[maxn][110], exam_sum[110], mini[maxn], maxi[maxn], s, n;

int solve(int e, int p) {
  if(p < 0) return -INF;
  if(e < 0) return 0;

  if(dp[e][p] != -1)
    return dp[e][p];

  int r = -INF;
  for(int pi = mini[e]; pi <= maxi[e]; pi++) {
    r = max(r, pi*exam_sum[e] + solve(e-1, p - pi));
  }
  return dp[e][p] = r;
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  while(scanf("%d%d", &s, &n)) {
    if((s|n) == 0)
      break;

    REP(i, 0, s) {
      REP(j, 0, n) {
        int note;
        scanf("%d", &note);
        if(i == 0) exam_sum[j] = 0;
        exam_sum[j] += note;
      }
    }

    REP(i, 0, n)
      scanf("%d%d", &mini[i], &maxi[i]);

    memset(dp, -1, sizeof(dp));
    double avg = (double)solve(n-1, 100) / s;

    int ans = (int)round(avg);

    printf("%d.%02d\n", ans/100, ans%100);
  }
}
