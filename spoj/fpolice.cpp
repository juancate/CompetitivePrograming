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

int N, T;

struct state {
  int r, t;

  state(int _r = INF, int _t = INF) {
    r = _r;
    t = _t;
  }

  bool operator<(const state& b) const {
    if(t > T && b.t > T)
      return true;

    if(t > T)
      return false;

    if(b.t > T)
      return true;

    return r < b.r;
  }

} dp[256][111];

int dist[111][111], risk[111][111];

int main() {
  int t;
  scanf("%d", &t);

  while(t--) {
    scanf("%d%d", &N, &T);

    for(int i = 1; i <= N; i++)
      for(int j = 1; j <= N; j++)
        scanf("%d", &dist[i][j]);

    for(int i = 1; i <= N; i++)
      for(int j = 1; j <= N; j++)
        scanf("%d", &risk[i][j]);

    for(int i = 0; i <= T; i++)
      for(int j = 0; j <= N; j++)
        dp[i][j] = state();

    for(int i = 0; i <= T; i++)
      dp[i][N] = state(0, 0);

    for(int i = 1; i <= T; i++) {
      for(int j = 1; j <= N; j++) {
        for(int k = 1; k <= N; k++) {
          if(j == k || i < dist[j][k])
            continue;

          state next(risk[j][k] + dp[i-dist[j][k]][k].r,
                     dist[j][k] + dp[i-dist[j][k]][k].t);

          if(next < dp[i][j])
            dp[i][j] = next;
        }
      }
    }

    if(dp[T][1].t > T) puts("-1");
    else printf("%d %d\n", dp[T][1].r, dp[T][1].t);
  }

  return 0;
}

