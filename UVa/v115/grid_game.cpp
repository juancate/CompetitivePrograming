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

int grid[10][10], col[10], n, best;

int solve(int bitmask, int c) {
    if(c == n) {
        int sum = 0;
        REP(i, 0, n)
            sum += grid[i][col[i]];
        best = min(best, sum);
    }

    for(int next = 0; next < n; next++) {
        if(bitmask & (1 << next)) continue;

        col[c] = next;
        solve(bitmask | (1 << next), c+1);
    }
}

int main() {
    int t; scanf("%d", &t);

    while(t--) {
        scanf("%d", &n);
        REP(i, 0, n) REP(j, 0, n)
            scanf("%d", &grid[i][j]);

        best = INF;
        solve(0, 0);
        printf("%d\n", best);
    }
}

