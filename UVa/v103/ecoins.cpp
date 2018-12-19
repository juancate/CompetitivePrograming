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

#define D(x) cerr << #x << " = " << (x) << endl
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

int coins[41][2], m, S;
int memo[41][310][310];

inline int sqr(int x) {
    return x*x;
}

int solve(int k, int r, int v) {
    int used = sqr(r) + sqr(v);
    if(used == S) return 0;
    if(used > S || k == m) return INF;

    if(memo[k][r][v] != -1) return memo[k][r][v];

    return memo[k][r][v] = min(solve(k+1, r, v),
                               1 + solve(k, r + coins[k][0], v + coins[k][1]));
}

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        scanf("%d%d", &m, &S);

        S = sqr(S);

        for(int i = 0; i < m; i++)
            scanf("%d%d", &coins[i][0], &coins[i][1]);

        memset(memo, -1, sizeof memo);
        int ans = solve(0, 0, 0);
        if(ans == INF) puts("not possible");
        else printf("%d\n", ans);
    }
    return 0;
}

