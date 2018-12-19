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

int rows[9], a, b, cnt;

bool place(int col, int trow) {
    for(int i = 1; i < col; i++) {
        if (rows[i] == trow || (abs(rows[i] - trow) == abs(i - col)))
            return false;
    }
    return true;
}

void backtracking(int col) {
    for(int row = 1; row <= 8; row++) {
        if(col != b && row == a) continue;
        if(col == b && row != a) continue;
        if(place(col, row)) {
            rows[col] = row;
            if(col == 8 && rows[b] == a) {
                printf("%2d      %d", ++cnt, rows[1]);
                for(int i = 2; i <= 8; i++)
                    printf(" %d", rows[i]);
                printf("\n");
            } else {
                backtracking(col + 1);
            }
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &a, &b);

        memset(rows, 0, sizeof(rows));
        cnt = 0;

        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");

        backtracking(1);

        if(t) puts("");
    }
}

