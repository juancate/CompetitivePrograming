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

#define SIZE (1 << 19)

char buff[SIZE], *p = buff + SIZE;

char read_char() {
    if( p == buff + SIZE ) {
        fread( buff, 1, SIZE, stdin );
        p = buff;
    }
    return *(p++);
}

int read_int() {
    char c;
    int r;

    while( !isdigit( c = read_char() ) );

    r = c-'0';
    while( isdigit( c = read_char() ) ) r = 10*r + c - '0';

    return r;
}


typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

struct rectangle {
    int x1, y1, x2, y2;

    rectangle(int _x1 = 0, int _y1 = 0, int _x2 = 0, int _y2 = 0) {
        x1 = _x1, y1 = _y1, x2 = _x2, y2 = _y2;
    }
} rs[10010], valids[10010];

int n;

int signum(int x) {
    if(x < 0) return -1; // point
    if(x > 0) return 1; // rectangle
    return 0; // none
}

bool intersects(const rectangle& a, const rectangle& b) {
    int sgnx = signum(min(a.x2, b.x2) - max(a.x1, b.x1));
    int sgny = signum(min(a.y2, b.y2) - max(a.y1, b.y1));

    return (sgnx == 1 && sgny == 1);
}

int main() {
    int t = read_int();

    REP(case_id, 1, t+1) {
        n = read_int();

        int64 area = 0;
        int sz = 0;

        for(int i = 0; i < n; i++) {
            rs[i].x1 = read_int(); rs[i].y1 = read_int();
            rs[i].x2 = read_int(); rs[i].y2 = read_int();

            bool ok = true;

            for(int j = 0; j < sz && ok; j++) {
                if(intersects(valids[j], rs[i])) {
                    ok = false;
                }
            }

            if(ok) {
                valids[sz].x1 = rs[i].x1, valids[sz].y1 = rs[i].y1;
                valids[sz].x2 = rs[i].x2, valids[sz].y2 = rs[i].y2;
                sz++;
                area += ((int64)abs(rs[i].x2 - rs[i].x1)) * ((int64)abs(rs[i].y2 - rs[i].y1));
            }
        }

        printf("Case %d: %lld\n", case_id, area);
    }
}

