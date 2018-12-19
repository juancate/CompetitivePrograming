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
#include <set>
#include <map>
#include <algorithm>

#define D(x) cerr << #x << " = " << x << endl
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

using namespace std;

long long w[65][65][65], ans[65][65][65];

int main() {
  ios_base::sync_with_stdio(false);

  int n, m, r;
  cin >> n >> m >> r;

  memset(ans, 0x3f, sizeof ans);

  for(int l = 1; l <= m; l++) {
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        cin >> w[l][i][j];
      }
    }
    for(int u = 1; u <= n; u++) {
      for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
          w[l][i][j] = min(w[l][i][j], w[l][i][u] + w[l][u][j]);
          ans[0][i][j] = min(ans[0][i][j], w[l][i][j]);
        }
      }
    }
  }

  for(int kk = 1; kk <= n; kk++) {
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        for(int l = 1; l <= n; l++) {
          ans[kk][i][j] = min(ans[kk][i][j], ans[kk-1][i][l] + ans[0][l][j]);
        }
      }
    }
  }

  for(int i = 0; i < r; i++) {
    int s, t, k;
    cin >> s >> t >> k;
    k = min(n, k);
    cout << ans[k][s][t] << endl;
  }

  return 0;
}

