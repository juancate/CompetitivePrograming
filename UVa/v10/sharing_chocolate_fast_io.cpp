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

namespace IO {
#define MAXBUFF (1<<19)
    char buffer[MAXBUFF], *p = buffer+MAXBUFF;

    inline char read_char() {
        if( p == buffer+MAXBUFF ) {
            fread( buffer, 1, MAXBUFF, stdin );
            p = buffer;
        }
        return *p++;
    }

    inline int read_signed_int() {
        char c;
        while( !isdigit(c = read_char()) and c != '-' );
        int sign = 1;
        if (c == '-') sign = -1, c = read_char();
        int ret = c-'0';
        while( isdigit(c = read_char()) ) ret = ret * 10 + c-'0';
        return ret * sign;
    }

    inline int read_unsigned_int() {
        char c;
        while( !isdigit(c = read_char()) );
        int ret = c-'0';
        while( isdigit(c = read_char()) ) ret = ret * 10 + c-'0';
        return ret;
    }
}
using namespace IO;

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
            if(!(sum[i] % d) && !(sum[i ^ next] % d)) {
                r |= go(d, mask | i) & go(d, mask | (i ^ next));
            }
            if(!r && !(sum[i] % d2) && !(sum[i ^ next] % d2)) {
                r |= go(sum[i] / d2, mask | (i ^ next)) & go(sum[i ^ next] / d2, mask | i);
            }

            if(r) break;
        }
    }
    return r;
}

int main() {
    int case_id = 1;
    while(true) {
        n = read_signed_int();
        if(!n) break;
        int w, h, t = 0;
        w = read_signed_int();
        h = read_signed_int();

        for(int i = 0; i < n; i++) {
            a[i] = read_signed_int();
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
