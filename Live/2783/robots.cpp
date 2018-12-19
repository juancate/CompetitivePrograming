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

#define UP -1
#define EAST 1

int dp[32][32], g[32][32], sol[32][32], garbage;

void clean(int r=24, int c=24) {
  if(r == 1 && c == 1) {
    g[r][c] = 0;
    return;
  }
  if(sol[r][c] == EAST)
    clean(r, c-1);
  else
    clean(r-1, c);
  g[r][c] = 0;
}

void run() {
  int r, c;
  memset(dp, 0, sizeof(dp));
  memset(sol, 0, sizeof(sol));

  for(r = 1; r < 25; r++) {
    dp[r][1] = dp[r-1][1] + g[r][1];
    sol[r][1] = UP;

    dp[1][r] = dp[1][r-1] + g[1][r];
    sol[1][r] = EAST;
  }

  for(r = 2; r < 25; r++) {
    for(c = 2; c < 25; c++) {
      dp[r][c] = g[r][c] + dp[r][c-1];
      sol[r][c] = EAST;

      if(g[r][c] + dp[r-1][c] > dp[r][c]) {
        dp[r][c] = g[r][c] + dp[r-1][c];
        sol[r][c] = UP;
      }
    }
  }
  for(r = 1; r < 25; r++) {
    for(c = 1; c < 25; c++)
      fprintf(stderr, "%d ", dp[r][c]);
    fprintf(stderr, "\n");
  }
  clean();
}

bool finished() {
  for(int i = 0; i < 25; i++)
    for(int j = 0; j < 25; j++)
      if(g[i][j])
        return false;
  return true;
}

int main() {
  int r, c;
  while(scanf("%d%d", &r, &c)) {
    if(r < 0 && c < 0)
      break;
    if(r == 0 && c == 0) {
      printf("0\n");
      continue;
    }

    memset(g, 0, sizeof(g));
    g[r][c] = 1;
    garbage = 1;

    while(scanf("%d%d", &r, &c)) {
      if(!(r|c)) break;
      g[r][c] = 1;
      garbage++;
    }

    int ans = 0;
    D(garbage);
    while(!finished()) {
      for(int i = 1; i < 25; i++) {
        for(int j = 1; j < 25; j++)
          fprintf(stderr, "%d ", g[i][j]);
        fprintf(stderr, "\n");
      }
      fprintf(stderr, "=============\n");
      run();
      ans++;
    }
    printf("%d\n", ans);
  }
  return 0;
}

