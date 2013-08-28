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

const int MAXN = 2000 + 10;

char A[MAXN], B[MAXN];
int dp[MAXN][MAXN];

int main() {
    int t; scanf("%d", &t);

    while(t--) {
        scanf("%s%s", A, B);
        int n = strlen(A);
        int m = strlen(B);

        memset(dp, 0x3f, sizeof(dp));

        for(int i = 1; i <= n; i++)
            dp[i][0] = i;

        for(int j = 1; j <= m; j++)
            dp[0][j] = j;

        dp[0][0] = 0;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                dp[i][j] = min(min(dp[i][j], dp[i-1][j] + 1),
                               min(dp[i][j-1] + 1,
                                   dp[i-1][j-1] + (A[i-1] != B[j-1])));
            }
        }
        printf("%d\n", dp[n][m]);
    }
}

