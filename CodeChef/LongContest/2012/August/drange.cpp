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
#include <climits>

#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

namespace IO {
    const int SIZE = 1 << 19;
    char buff[SIZE], *p = buff + SIZE;

    inline char read_char() {
        if( p == buff + SIZE ) {
            fread( buff, 1, SIZE, stdin );
            p = buff;
        }
        return *(p++);
    }

    inline int read_int() {
        char c;

        while( !isdigit( c = read_char() ) );

        int r = c-'0';
        while( isdigit( c = read_char() ) ) r = 10*r + c - '0';

        return r;
    }
}
using namespace IO;

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

const int MAXN = 1e6 + 10;

int diff[MAXN];

int main() {
    int t, n, m;
    t = read_int();

    while(t--) {
        n = read_int();
        m = read_int();

        for(int i = 0; i <= n; i++)
            diff[i] = 1;

        for(int i = 0; i < m; i++) {
            int w, x, y, z;
            w = read_int(), x = read_int(), y = read_int(), z = read_int();
            x--, y--;

            if(w == 2) z = -z;

            diff[x] += z;
            diff[y+1] -= z;
        }

        int curr = diff[0];
        int min_val = INT_MAX;
        int max_val = -INT_MAX;

        for(int i = 0; i < n; i++, curr += diff[i]) {
            min_val = min(min_val, curr);
            max_val = max(max_val, curr);
        }

        int ans = max_val - min_val;

        printf("%d\n", ans);
    }
}

