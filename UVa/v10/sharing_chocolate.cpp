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

int a[16], sum[1<<16], n;
char dp[110][1<<16];

char go(int d, int mask) {
    int next = ((1 << n) - 1) ^ mask; // next unserved

    if(!(next & (next - 1)))
        return dp[d][mask] = 1;
    char& r = dp[d][mask];

    if(r == -1) {
        int d2 = sum[next] / d;
        r = 0;
        for(int i = (next-1) & next; i > (next ^ i); i = (i-1) & next) {
            if(sum[i] % d == 0 && sum[i ^ next] % d == 0) {
                r |= go(d, mask | i) & go(d, mask | (i ^ next));
            }
            if(!r && sum[i] % d2 == 0 && sum[i ^ next] % d2 == 0) {
                r |= go(sum[i] / d2, mask | (i ^ next)) & go(sum[i ^ next] / d2, mask | i);
            }

            if(r) break;
        }
    }
    return r;
}

int main() {
    int case_id = 1;
    while(scanf("%d", &n) != EOF) {
        if(!n) break;
        int w, h, t = 0;
        scanf("%d%d", &w, &h);

        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            t += a[i];
        }

        if(t != w*h) {
            printf("Case %d: No\n", case_id++);
            continue;
        }

        sum[0] = 0;
        for(int i = 0; i < n; i++) {
            sum[1 << i] = a[i];
        }

        for(int i = 1; i < (1<<n); i++) {
            int last = i & -i;
            sum[i] = sum[last] + sum[i ^ last];
        }
        memset(dp, -1, sizeof dp);

        printf("Case %d: ", case_id++);
        if(go(min(w,h), 0) > 0) puts("Yes");
        else puts("No");
    }
    return 0;
}
