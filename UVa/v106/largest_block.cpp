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

const int MAXN = 111;

int board[MAXN][MAXN], sum[MAXN], n;

int kadane() {
    int max_sum = -1;
    int current_sum = 0;
    for(int j = 0; j < n; j++) {
        current_sum = max(sum[j], current_sum + sum[j]);
        max_sum = max(max_sum, current_sum);
    }
    return max_sum;
}

int main() {
    int p, b;
    scanf("%d", &p);
    while(p--) {
        scanf("%d%d", &n, &b);
        REP(i, 0, n) REP(j, 0, n) board[i][j] = 1;

        REP(k, 0, b) {
            int r1, c1, r2, c2;
            scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
            REP(i, r1-1, r2) REP(j, c1-1, c2) board[i][j] = -100000;
        }

        int ans = -1;

        REP(i, 0, n) {
            REP(j, 0, n)
                sum[j] = 0;
            REP(j, i, n) {
                REP(k, 0, n)
                    sum[k] += board[j][k];
                ans = max(ans, kadane());
            }
        }

        if(ans < 0) ans = 0;
        printf("%d\n", ans);
    }
}

