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

const int MAXN = 111;

int dp[MAXN][MAXN];
vector<int> G[MAXN];

int main() {
    int n, case_id = 0;
    while(~scanf("%d", &n) && n) {
        REP(i, 0, n) G[i].clear();
        REP(i, 0, n) REP(j, 0, n) {
            dp[i][j] = -INF;
            if(i == j) dp[i][j] = 0;
        }

        int start; scanf("%d", &start); start--;

        int p, q;
        while(~scanf("%d%d", &p, &q) && (p|q)) {
            p--, q--;
            dp[p][q] = 1;
        }

        REP(k, 0, n) REP(i, 0, n) REP(j, 0, n)
            dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j]);

        int max_id = 0;

        REP(i, 0, n) {
            if(dp[start][max_id] < dp[start][i])
                max_id = i;
        }

        start++, max_id++;
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n", ++case_id, start, dp[start-1][max_id-1], max_id);
        puts("");
    }
}

