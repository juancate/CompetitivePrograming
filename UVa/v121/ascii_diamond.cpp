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

char get(int n, int x, int y) {
  x %= 2*n-1, y %= 2*n-1;
  int d = abs(n-x-1) + abs(n-y-1);
  if(d < n)
    return (d%26 + 'a');
  return '.';
}

int main() {
  int n, r1, c1, r2, c2, test_case = 1;

  while(scanf("%d", &n) && n) {
    scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
    printf("Case %d:\n", test_case++);
    for(int i = r1; i <= r2; i++) {
      string ln;
      for(int j = c1; j <= c2; j++)
        ln.push_back(get(n, j, i));
      puts(ln.c_str());
    }
  }

  return 0;
}

