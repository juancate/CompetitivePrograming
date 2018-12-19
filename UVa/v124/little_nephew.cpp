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

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

int main() {
    while(true) {
        int a = read_int(), b = read_int(), c = read_int();
        int d = read_int(), e = read_int();

        if(a == 0) break;

        int ans = a * b * c * (d * d) * (e * e);

        printf("%d\n", ans);
    }
}

