/*
ID: jcamarg1
PROG: barn1
LANG: C++
*/

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

const int maxn = 220;
int c, d[maxn][maxn], a[maxn], memo[maxn][maxn];

int solve(int i, int b) {
  if(i == c) {
    if(b >= 0) return 0;
    else return INF;
  }
  if(memo[i][b] != -1)
    return memo[i][b];
  int best = INF;
  for(int j = i; j < c; j++) {
    int curr = a[j] - a[i] + 1;
    curr += solve(j+1, b-1);
    best = min(best, curr);
  }
  return memo[i][b] = best;
}

int main() {
  freopen("barn1.in", "r", stdin);
  freopen("barn1.out", "w", stdout);

  int m, n;
  scanf("%d%d%d", &m, &n, &c);

  for(int i = 0; i < c; i++) {
    scanf("%d", &a[i]);
  }
  sort(a, a+c);
  memset(memo, -1, sizeof memo);
  int ans = solve(0, m);
  printf("%d\n", ans);

  return 0;
}

