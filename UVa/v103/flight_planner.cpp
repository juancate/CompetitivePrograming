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

int wind[11][1010], dp[11][1010], x;

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int x;
        scanf("%d", &x);
        x /= 100;

        for(int i = 0; i < 10; i++)
            for(int j = 0; j < x; j++)
                scanf("%d", &wind[9-i][j]);

        memset(dp, 0x3f, sizeof dp);

        dp[0][0] = 0;
        for(int c = 1; c <= x; c++) {
            for(int r = c != x; r < 10; r++) {
                dp[r][c] = min(dp[r][c], dp[r][c-1] - wind[r][c-1] + 30);

                if(r) dp[r][c] = min(dp[r][c], dp[r-1][c-1] - wind[r-1][c-1] + 60);
                if(r < 9) dp[r][c] = min(dp[r][c], dp[r+1][c-1] - wind[r+1][c-1] + 20);
            }
        }

        printf("%d\n\n", dp[0][x]);
    }
    return 0;
}

