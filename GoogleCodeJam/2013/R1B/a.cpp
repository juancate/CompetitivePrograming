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

int b[111], n;
map< pair<long long, int>, int> memo;

int solve(long long a, int  i) {
  if(i == n)
    return 0;
  pair<long long,int> p = make_pair(a,i);
  if(memo.count(p))
    return memo[p];

  int f = INF, s = INF;
  if(a <= b[i] && a-1 > 0)
    f = 1 + solve(a+a-1, i+1);
  else if(a > b[i])
    f = solve(a+b[i], i+1);

  if(a < b[i] || (a == b[i] && a-1 == 0))
    s = 1 + solve(a, i+1);

  return memo[p] = min(f, s);
}

int main() {
  int t;
  scanf("%d", &t);

  for(int run = 1; run <= t; run++) {
    long long a;
    scanf("%lld%d", &a, &n);

    for(int i = 0; i < n; i++)
      scanf("%d", b+i);

    sort(b, b+n);
    memo.clear();
    int ans = solve(a, 0);
    printf("Case #%d: %d\n", run, ans);
  }

  return 0;
}

