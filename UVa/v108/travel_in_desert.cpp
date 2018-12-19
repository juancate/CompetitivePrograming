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

// Problem: Travel in desert
// Algorithm: Floyd warshall, Shortest-path 2 times + Greedy
// Status: Accepted

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

const int maxn = 110;
const int maxe = 10010;

int n, E, start, end;
int S[maxe], T[maxe], D[maxe], R[maxe], dp[maxn][maxn], path[maxn][maxn];

void print_path(int i, int j, bool p)
{
    if(path[i][j] < 0)
    {
        if(!p) printf("%d ", i+1);
        printf("%d", j+1);
        if(j != end) printf(" ");
    }
    else
    {
        print_path(i, path[i][j], p);
        print_path(path[i][j], j, true);
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "a", stdout);
    freopen("output.txt", "a", stderr);
#endif

    while(~scanf("%d%d", &n, &E)) {
        scanf("%d%d", &start, &end);
        start--; end--;

        memset(dp, 0x3f, sizeof(dp));
        REP(i, 0, n) dp[i][i] = 0;

        REP(i, 0, E) {
            int a, b; scanf("%d%d", &a, &b); a--, b--;
            int r, rd, d, dd; scanf("%d.%d%d.%d", &r, &rd, &d, &dd);

            S[i] = a; T[i] = b;
            D[i] = d * 10 + dd; R[i] = r * 10 + rd;

            dp[S[i]][T[i]] = min(dp[S[i]][T[i]], R[i]);
            dp[T[i]][S[i]] = min(dp[T[i]][S[i]], R[i]);
        }

        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    dp[i][j] = min(dp[i][j], max(dp[i][k], dp[k][j]));

        int min_temperature = dp[start][end];

        memset(dp, 0x3f, sizeof(dp));
        REP(i, 0, n) dp[i][i] = 0;

        memset(path, -1, sizeof(path));

        for(int i = 0; i < E; i++) {
            if(R[i] <= min_temperature) {
                dp[S[i]][T[i]] = min(dp[S[i]][T[i]], D[i]);
                dp[T[i]][S[i]] = min(dp[T[i]][S[i]], D[i]);
            }
        }

        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    if(dp[i][k] + dp[k][j] < dp[i][j]) {
                        dp[i][j] = dp[i][k] + dp[k][j];
                        path[i][j] = k;
                    }


        int min_dist = dp[start][end];

        print_path(start, end, false);
        printf("\n%.1lf %.1lf\n", min_dist / 10., min_temperature / 10.);
    }
}
