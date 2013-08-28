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

// Problem: Trouble of 13-Dots
// Algorithm: DP, Knapsack
// Status: Accepted

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

const int maxn = 110;
const int maxm = 11000;

int n, m, cost[maxn], profit[maxn];
int dp[maxn][maxm];

int solve(int item, int money) {
    if(item == n) {
        int diff = m + 200 - money;
        if(diff > m && diff <= 2000)
            return -INF;
        return 0;
    }

    if(dp[item][money] != -1) return dp[item][money];

    dp[item][money] = solve(item + 1, money);

    if(money - cost[item] >= 0) {
        dp[item][money] = max(dp[item][money],
                              profit[item] + solve(item + 1, money - cost[item]));
    }

    return dp[item][money];
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while(~scanf("%d%d", &m, &n)) {
        REP(i, 0, n) {
            scanf("%d%d", &cost[i], &profit[i]);
        }

        memset(dp, -1, sizeof(dp));
        printf("%d\n", solve(0, m + 200));
    }
}
