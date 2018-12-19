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

char s[20];
int col[20];
long long dp[20][20];

int main() {
    while(scanf("%s", s) != EOF) {
        int n = (int)strlen(s);
        for(int i = 0; s[i]; i++) {
            if(s[i] == '?')
                col[i+1] = 0;
            else if(isdigit(s[i]))
                col[i+1] = s[i] - '0';
            else
                col[i+1] = s[i] - 'A' + 10;
        }

        memset(dp, 0, sizeof dp);

        if(col[1] != 0) {
            dp[col[1]][1] = 1;
        }
        else {
            for(int i = 1; i <= n; i++)
                dp[i][1] = 1;
        }

        for(int c = 2; c <= n; c++) {
            if(col[c] != 0) {
                if(col[c-1] != 0) {
                    if(col[c-1] < col[c]-1 || col[c]+1 < col[c-1])
                        dp[col[c]][c] = dp[col[c-1]][c-1];
                }
                else {
                    for(int r = 1; r < col[c]-1; r++)
                        dp[col[c]][c] += dp[r][c-1];
                    for(int r = col[c]+2; r <= n; r++)
                        dp[col[c]][c] += dp[r][c-1];
                }
            }
            else {
                for(int r = 1; r <= n; r++) {
                    if(col[c-1] != 0) {
                        if(col[c-1] < r-1 || r+1 < col[c-1])
                            dp[r][c] = dp[col[c-1]][c-1];
                    }
                    else {
                        for(int r2 = 1; r2 < r-1; r2++)
                            dp[r][c] += dp[r2][c-1];
                        for(int r2 = r+2; r2 <= n; r2++)
                            dp[r][c] += dp[r2][c-1];
                    }
                }
            }
        }

        long long ans = 0;
        for(int r = 1; r <= n; r++)
            ans += dp[r][n];
        printf("%lld\n", ans);
    }
    return 0;
}

