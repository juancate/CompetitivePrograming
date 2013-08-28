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


// make rectangles and use binary search to look for intersections.

int main() {
    int t;
    scanf("%d", &t);

    for(int case_id = 1; case_id <= t; case_id++) {
        int W, H, P, Q, N, X, Y, a, b, c, d;
        scanf("%d %d %d %d %d %d %d %d %d %d %d",
              &W, &H, &P, &Q, &N, &X, &Y, &a, &b, &c, &d);

        set< pair<int, int> > S;

        printf("%d %d\n", X, Y);
        S.insert( make_pair(X, Y) );
        while(true) {
            int x = (X * a + Y * b + 1) % W;
            int y = (X * c + Y * d + 1) % H;
            X = x;
            Y = y;
            if(S.count(make_pair(x, y))) {
                puts("CYCLE!!!!!!!!!!");
                break;
            }
            S.insert( make_pair(X, Y) );
            printf("%d %d\n", X, Y);
        }
        printf("cycle length = %d\n", (int)S.size());
    }

    return 0;
}

