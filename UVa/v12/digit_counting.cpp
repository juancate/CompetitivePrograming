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

int cnt[10000][10];

void calc(int x) {
  for(int i = 0; i < 10; i++) {
    cnt[x][i] = cnt[x-1][i];
  }
  int y = x;
  while(y > 0) {
    cnt[x][y%10]++;
    y /= 10;
  }
}

int main() {
  memset(cnt, 0, sizeof cnt);
  for(int i = 1; i < 10000; i++)
    calc(i);

  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < 10; i++) {
      if(i) printf(" ");
      printf("%d", cnt[n][i]);
    }
    printf("\n");
  }

  return 0;
}

