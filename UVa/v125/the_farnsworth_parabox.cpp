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

const int maxn = 110;

int n, m;
int G[maxn][maxn];

void floyd_warshall() {
  for(int k = 0; k < n; k++)
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
}

int main() {
  while(scanf("%d%d", &n, &m) && (n|m)) {
    memset(G, 0x3f, sizeof(G));

    REP(i, 0, n) G[i][i] = 0;

    REP(i, 0, m) {
      int a, b, t;
      scanf("%d%d%d", &a, &b, &t);
      a--, b--;
      G[a][b] = t;
      G[b][a] = -t;
    }

    floyd_warshall();
    floyd_warshall();

    puts((G[0][0] < 0)? "Y" : "N");
  }
}

