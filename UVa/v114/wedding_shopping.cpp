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

#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

int M, C;
int memo[211][25], price[25][25];

int solve(int money, int state) {
    if(money < 0) return -INF;

    if(state == C) return M - money;

    if(memo[money][state] != -1) return memo[money][state];

    int ret = -INF;

    for(int i = 1; i <= price[state][0]; i++)
        ret = max(ret, solve(money - price[state][i], state + 1));

    return memo[money][state] = ret;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &M, &C);

        for(int i = 0; i < C; i++) {
            scanf("%d", &price[i][0]);
            for(int j = 1; j <= price[i][0]; j++)
                scanf("%d", &price[i][j]);
        }

        memset(memo, -1, sizeof(memo));

        int ans = solve(M, 0);

        if(ans < 0) puts("no solution");
        else printf("%d\n", ans);
    }
}

