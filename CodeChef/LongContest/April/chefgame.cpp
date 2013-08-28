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

// Algorithm: Prim - Maximum ST, in a complete graph.

const int mod = 747474747;

int n, d;
long long points[6667][5], max_dist[6667];
bool seen[6667];

long long dist2(int i, int j) {
  long long r = 0;
  for(int k = 0; k < d; k++) {
    long long diff = points[i][k] - points[j][k];
    r += diff * diff;
  }
  return r;
}

int main() {
  int t;
  scanf("%d", &t);

  while(t--) {
    scanf("%d%d", &n, &d);
    for(int i = 0; i < n; i++)
      for(int j = 0; j < d; j++)
        scanf("%lld", &points[i][j]);

    memset(seen, 0, n);
    memset(max_dist, 0, n*sizeof(long long));

    long long ans = 1;

    seen[0] = true;
    for(int u = 0; u < n; u++)
      if(!seen[u])
        max_dist[u] = max(dist2(0, u), max_dist[u]);

    for(int i = 1; i < n ; i++) {
      int v = -1;
      long long mx = 0;
      for(int j = 0; j < n; j++)
        if(!seen[j] && max_dist[j] > mx)
          v = j, mx = max_dist[j];

      if(mx == 0) continue;
      ans = ((mx % mod) * ans) % mod;

      seen[v] = true;

      for(int u = 0; u < n; u++) if(!seen[u]) {
        long long new_dist = dist2(v, u);
        if(new_dist > max_dist[u]) {
          max_dist[u] = new_dist;
          // set parent
        }
      }
    }
    printf("%lld\n", ans);
  }

  return 0;
}

