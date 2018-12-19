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

namespace IO {
   #define MAXBUFF (1<<24)
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

#define LSOne(S) (S & (-S))

int n, t[200010];

void ft_create(int n) {
    n++;
    memset(t, 0, n * sizeof(int));
}

int ft_rsq(int b) {
    int sum = 0;
    for(; b; b -= LSOne(b)) sum += t[b];
    return sum;
}

int ft_rsq(int a, int b) {
    return ft_rsq(b) - (a == 1? 0 : ft_rsq(a-1));
}

void ft_adjust(int k, int v) {
    for(; k <= n; k += LSOne(k)) t[k] += v;
}

int main() {
    int case_id = 0;

    while((n = read_unsigned_int())) {
        ft_create(n);

        for(int i = 1; i <= n; i++) {
            int x = read_unsigned_int();
            ft_adjust(i, x - ft_rsq(i, i));
        }

        if(case_id) puts("");

        printf("Case %d:\n", ++case_id);

        while(true) {
            char op = read_char();
            if(op == 'E') break;
            int i = read_unsigned_int();
            int j = read_unsigned_int();

            if(op == 'S')
                ft_adjust(i, j - ft_rsq(i, i));
            else {
                printf("%d\n", ft_rsq(i, j));
            }
        }
    }
    return 0;
}

