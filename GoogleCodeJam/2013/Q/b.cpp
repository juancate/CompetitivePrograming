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

int a[111][111];

int main() {
  int t;
  scanf("%d", &t);

  for(int case_id = 1; case_id <= t; case_id++) {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        scanf("%d", &a[i][j]);

    bool can = true;

    for(int i = 0; i < n && can; i++) {
      for(int j = 0; j < m && can; j++) {
        int curr = a[i][j];
        bool can_row = true, can_col = true;
        for(int k = 0; k < n; k++)
          if(a[k][j] > curr)
            can_row = false;
        for(int k = 0; k < m; k++)
          if(a[i][k] > curr)
            can_col = false;
        can = (can_row || can_col);
      }
    }

    printf("Case #%d: %s\n", case_id, can? "YES":"NO");
  }

  return 0;
}

