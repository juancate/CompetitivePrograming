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

const int mod = 10000007;

int f[100010];

int main() {
  int t;
  scanf("%d", &t);

  for(int casei = 1; casei <= t; casei++) {
    long long n;
    scanf("%d %d %d %d %d %d %d",
          &f[0], &f[1], &f[2], &f[3], &f[4], &f[5], &n);

    for(int i = 0; i < 6; i++)
      f[i] %= mod;

    f[6] = 0;
    for(int i = 1; i <= 6; i++)
      f[6] = (f[6] + f[6-i]) % mod;

    for(int i = 7; i <= n; i++)
      f[i] = (f[i-1] + f[i-1] - f[i-7] + mod) % mod;

    printf("Case %d: %d\n", casei, (int)f[n]);
  }

  return 0;
}

