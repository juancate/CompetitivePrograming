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

const int maxn = 2010;

int n;
int memo[maxn][maxn], w[maxn], c[maxn];

int solve(int s, int i) {
  if(s == 0) return 0;
  if(i == n) return 0;

  if(memo[s][i] != -1) return memo[s][i];

  if(s - w[i] >= 0)
    memo[s][i] = c[i] + solve(s - w[i], i+1);
  memo[s][i] = max(memo[s][i], solve(s, i+1));
  return memo[s][i];
}

int main() {
  int s;
  scanf("%d%d", &s, &n);
  for(int i = 0; i < n; i++) {
    scanf("%d%d", &w[i], &c[i]);
  }

  memset(memo, -1, sizeof memo);

  printf("%d\n", solve(s, 0));
  return 0;
}

