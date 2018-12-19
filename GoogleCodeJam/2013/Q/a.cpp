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

char b[10][10];

int solve() {
  int cnt_o = 0, cnt_x = 0;

  for(int i = 0; i < 4; i++) {
    cnt_o = cnt_x = 0;
    for(int j = 0; j < 4; j++) {
      if(b[i][j] == 'T') cnt_o++, cnt_x++;
      if(b[i][j] == 'X') cnt_x++;
      if(b[i][j] == 'O') cnt_o++;
    }
    if(cnt_x == 4) return 0;
    if(cnt_o == 4) return 1;
  }

  for(int i = 0; i < 4; i++) {
    cnt_o = cnt_x = 0;
    for(int j = 0; j < 4; j++) {
      if(b[j][i] == 'T') cnt_o++, cnt_x++;
      if(b[j][i] == 'X') cnt_x++;
      if(b[j][i] == 'O') cnt_o++;
    }
    if(cnt_x == 4) return 0;
    if(cnt_o == 4) return 1;
  }

  cnt_o = cnt_x = 0;
  for(int i = 0; i < 4; i++) {
    if(b[i][i] == 'T') cnt_o++, cnt_x++;
    if(b[i][i] == 'X') cnt_x++;
    if(b[i][i] == 'O') cnt_o++;
  }
  if(cnt_x == 4) return 0;
  if(cnt_o == 4) return 1;

  cnt_o = cnt_x = 0;
  for(int i = 0; i < 4; i++) {
    if(b[i][3-i] == 'T') cnt_o++, cnt_x++;
    if(b[i][3-i] == 'X') cnt_x++;
    if(b[i][3-i] == 'O') cnt_o++;
  }
  if(cnt_x == 4) return 0;
  if(cnt_o == 4) return 1;

  return -1;
}

int main() {
  int t;
  scanf("%d", &t);

  for(int case_id = 1; case_id <= t; case_id++) {
    int empty_cells = 0;
    for(int i = 0; i < 4; i++) {
      scanf("%s", b[i]);
      for(int j = 0; b[i][j]; j++)
        empty_cells += b[i][j] == '.';
    }
    int ans = solve();

    printf("Case #%d: ", case_id);
    if(ans < 0) {
      if(empty_cells > 0) puts("Game has not completed");
      else if(empty_cells == 0) puts("Draw");
    }
    else if(ans == 0)
      puts("X won");
    else if(ans == 1)
      puts("O won");
  }

  return 0;
}

