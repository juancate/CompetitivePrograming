/*
ID: jcamarg1
PROG: milk
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

pair<int,int> f[5001];

int main() {
  freopen("milk.in", "r", stdin);
  freopen("milk.out", "w", stdout);

  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 0; i < m; i++) {
    scanf("%d%d", &f[i].first, &f[i].second);
  }
  sort(f, f+m);

  long long p = 0;
  for(int i = 0; i < m; i++) {
    if(n == 0) break;
    if(f[i].second <= n) {
      n -= f[i].second;
      p += f[i].first * f[i].second;
    }
    else {
      p += f[i].first * n;
      n = 0;
    }
  }
  printf("%lld\n", p);

  return 0;
}

