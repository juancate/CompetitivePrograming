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
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

int n, board[111][111], memo[111][111];

int solve(int row, int col) {
    if(row == n) return 0;

    if(memo[row][col] != -1) return memo[row][col];

    int ret = -1;

    for(int i = -1; i <= 1; i++) {
        if(col + i >= 0 && col + i < n) {
            ret = max(ret, board[row][col] + solve(row+1, col+i));
        }
    }

    return memo[row][col] = ret;
}

int main() {
    while(~scanf("%d", &n) && n) {
        REP(i, 0, n) REP(j, 0, n)
            scanf("%d", &board[i][j]);

        memset(memo, -1, sizeof(memo));

        int ans = -1;
        REP(i, 0, n) {
            ans = max(ans, solve(0, i));
        }

        printf("%d\n", ans);
    }
}

