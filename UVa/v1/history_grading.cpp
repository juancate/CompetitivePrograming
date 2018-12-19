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

int ordered[21], grades[21];
int dp[21][21];

int main() {
    int n, x;
    scanf("%d", &n);

    REP(i, 0, n) {
        scanf("%d", &x);
        ordered[x-1] = i;
    }

    while(~scanf("%d", &x)) {
        grades[x-1] = 0;

        REP(i, 1, n) {
            scanf("%d", &x);
            grades[x-1] = i;
        }

        memset(dp, 0, sizeof(dp));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grades[j] == ordered[i]) {
                    dp[i+1][j+1] = dp[i][j] + 1;
                } else {
                    dp[i+1][j+1] = max(dp[i+1][j+1], max(dp[i][j+1], dp[i+1][j]));
                }
            }
        }

        printf("%d\n", dp[n][n]);
    }
}

