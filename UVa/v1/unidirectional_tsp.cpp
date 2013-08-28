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

const int INF = 0x3f3f3f3f;
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

const int max_rows = 11;
const int max_cols = 111;

int m, n;
int grid[max_rows][max_cols];
int dp[max_rows][max_cols], sol[max_rows][max_cols];

int main() {
    while(~scanf("%d%d", &m, &n)) {
        memset(dp, 0, sizeof(dp));
        memset(sol, -1, sizeof(sol));

        REP(i, 0, m) REP(j, 0, n) scanf("%d", &grid[i][j]);


        REP(i, 0, m) dp[i][n-1] = grid[i][n-1];

        for(int j = n-2; j >= 0; j--) {
            for(int i = 0; i < m; i++) {
                int ret = INF;

                for(int k = -1; k <= 1; k++) {
                    int current = (i + k + m) % m;
                    int val = grid[i][j];

                    if(ret >= val + dp[current][j+1]) {
                        if(ret > val + dp[current][j+1] || sol[i][j] == -1 || sol[i][j] > current)
                            sol[i][j] = current;
                        ret = val + dp[current][j+1];
                    }
                }

                dp[i][j] = ret;
            }
        }

        int min_row = 0;
        for(int i = 1; i < m; i++)
            if(dp[min_row][0] > dp[i][0])
                min_row = i;

        int ans = dp[min_row][0];

        string min_path = "Z";

        for(int i = 0; i < m; i++) {
            if(dp[i][0] == ans) {
                int current = i;
                vector<int> s(n);
                int col = 0;

                while(col < n) {
                    s[col] = current+1;
                    current = sol[current][col];
                    col++;
                }

                stringstream ss;
                REP(k, 0, s.size()) {
                    if(k) ss << ' ';
                    ss << s[k];
                }

                string curr_path = ss.str();
                if(curr_path < min_path)
                    min_path = curr_path;
            }
        }

        puts(min_path.c_str());
        printf("%d\n", ans);
    }
}

