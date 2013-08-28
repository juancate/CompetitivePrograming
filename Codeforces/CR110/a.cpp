#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
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

#define D(x) cerr << #x << " = " << x << endl;
#define REP(i,n) for(int i=0; i<n; i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)

#define INF 1<<30
#define EPS 1e-13

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  int board[n][n], rows[n], cols[n];

  memset(board, 0, sizeof(board));
  memset(rows, 0, sizeof(rows));
  memset(cols, 0, sizeof(cols));

  REP(i,n) REP(j, n) {
    cin >> board[i][j];
    rows[i] += board[i][j];
    cols[j] += board[i][j];
  }
  int ans = 0;
  REP(i,n) {
    REP(j,n) {
      if(cols[j] > rows[i]) ans++;
    }
  }
  cout << ans << endl;
}

