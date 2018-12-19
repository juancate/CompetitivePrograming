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

int m, memo[22][80][1010], w[1010], o[1010], n[1010];

int solve(int oxy, int nitro, int i) {
  if(i == m && (oxy > 0 || nitro > 0))
      return INF;
  if((oxy == 0 && nitro == 0) || i == m)
    return 0;

  if(memo[oxy][nitro][i] != -1)
    return memo[oxy][nitro][i];

  int& r = memo[oxy][nitro][i];

  r = min(w[i] + solve(max(0, oxy-o[i]), max(0, nitro-n[i]), i+1),
          solve(oxy, nitro, i+1));

  return r;
}

int main() {
  int t;
  scanf("%d", &t);

  while(t--) {
    int O, N;
    scanf("%d%d", &O, &N);

    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
      scanf("%d%d%d", &o[i], &n[i], &w[i]);
    }

    memset(memo, -1, sizeof memo);
    printf("%d\n", solve(O, N, 0));
  }

  return 0;
}

