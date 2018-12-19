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
typedef unsigned long long uint64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

const int maxn = 25;
const int maxm = 151;

uint64 all[maxn], dp[maxn][maxm+10];

uint64 solve(int n, int x) {
    if(n < 0 || x < 0) return 0;

    uint64& r = dp[n][x];
    if(r == -1) {
        r = 0;
        for(int k = 1; k <= 6; k++)
            r += solve(n - 1, x - k);
    }
    return r;
}

int main() {
    all[0] = 1;
    for(int i = 1; i < maxn; i++)
        all[i] = 6 * all[i-1];

    for(int i = 0; i < maxn; i++)
        for(int j = 0; j < maxm; j++)
            dp[i][j] = -1;

    for(int i = 0; i < maxm; i++) dp[0][i] = 0;
    for(int i = 0; i < maxn; i++) dp[i][0] = 0;
    dp[0][0] = 1;

    for(int i = 0; i < maxn; i++)
        for(int j = 0; j < maxm; j++)
            solve(i, j);

    for(int i = 0; i < maxn; i++)
        for(int j = maxm; j >= 0; j--)
            dp[i][j] += dp[i][j+1];

    int n, x;
    while(scanf("%d%d", &n, &x)) {
        if(!(n|x)) break;
        uint64 g = __gcd(dp[n][x], all[n]);

        printf("%llu", dp[n][x] / g);
        if(all[n] != g && dp[n][x] != 0)
            printf("/%llu", all[n] / g);
        printf("\n");
    }

    return 0;
}

