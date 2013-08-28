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

#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

int dist[15][15], memo[15][1<<15];
int x[15], y[15], width, heigth, n;

int tsp(int pos, int bitmask) {
    if(bitmask == (1 << n) - 1)
        return dist[pos][0];

    if(memo[pos][bitmask] != -1)
        return memo[pos][bitmask];

    int ret = INF;

    for(int next = 0; next < n; next++) {
        if((bitmask & (1 << next)) == 0)
            ret = min(ret, dist[pos][next] + tsp(next, bitmask | (1 << next)));
    }

    return memo[pos][bitmask] = ret;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &width, &heigth);
        scanf("%d%d", &x[0], &y[0]);

        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d%d", &x[i], &y[i]);
            for(int j = i-1; j >= 0; j--) {
                dist[i][j] = dist[j][i] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
            }
        }
        n++;

        memset(memo, -1, sizeof(memo));

        int ans = tsp(0, 1);
        printf("The shortest path has length %d\n", ans);
    }
}

