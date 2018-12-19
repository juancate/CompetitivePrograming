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

const int maxn = 20;

int n, s[maxn], g[maxn];
pair<int, int> memo[1<<maxn];

pair<int, int> solve(int mask) {

    if(mask == ((1 << n) - 1)) {
        return make_pair(0, 0);
    }

    if(memo[mask] != make_pair(-1, -1))
        return memo[mask];

    pair<int, int> best = make_pair(INF, INF);

    for(int i = 0; i < n; i++) {
        if((mask & (1 << i)) == 0) {
            int next_mask = (mask | (1 << i));

            pair<int, int> next = solve(next_mask);
            next.first += s[i];
            next.second = max(next.first, next.second) + g[i];

            if(next.second < best.second)
                best = next;
        }
    }

    return memo[mask] = best;
}

int main() {
    while(~scanf("%d", &n)) {
        REP(i, 0, n) scanf("%d", &s[i]);
        REP(i, 0, n) scanf("%d", &g[i]);

        fill_n(memo, (1<<n), make_pair(-1, -1));

        printf("%d\n", solve(0).second);
    }
}

