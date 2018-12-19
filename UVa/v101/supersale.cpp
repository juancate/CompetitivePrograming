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

int N, G;
int memo[1111][31], W[1111], V[1111];

int solve(int item, int capacity) {
    if(capacity == 0 || item == N)
        return 0;

    if(memo[item][capacity] != -1)
        return memo[item][capacity];

    if(W[item] > capacity)
        return memo[item][capacity] = solve(item + 1, capacity);

    return memo[item][capacity] = max(V[item] + solve(item + 1, capacity - W[item]),
                                      solve(item + 1, capacity));
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &N);

        for(int i = 0; i < N; i++)
            scanf("%d%d", &V[i], &W[i]);

        memset(memo, -1 , sizeof(memo));
        int ans = 0;

        scanf("%d", &G);
        while(G--) {
            int w;
            scanf("%d", &w);
            ans += solve(0, w);
        }
        printf("%d\n", ans);
    }
}

