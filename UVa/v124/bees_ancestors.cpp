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

int64 ancestors[82];

int main() {
    ancestors[0] = ancestors[1] = 1;
    REP(i, 2, 82)
        ancestors[i] = ancestors[i-1] + ancestors[i-2];

    int n;
    while((n = read_int())) {
        printf("%lld\n", ancestors[n]);
    }
}

