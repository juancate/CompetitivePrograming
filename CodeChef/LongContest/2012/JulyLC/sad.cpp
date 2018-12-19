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
#define FOREACH(it,v) for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

const int MAXN = 111;

int R, C;
int gifts[MAXN][MAXN], min_row[MAXN], max_col[MAXN];

int main() {
    while(~scanf("%d%d", &R, &C)) {
        REP(i, 0, R) {
            REP(j, 0, C) scanf("%d", &gifts[i][j]);
        }

        REP(i, 0, R) {
            min_row[i] = gifts[i][0];
            REP(j, 1, C)
                if(gifts[i][j] < min_row[i])
                    min_row[i] = gifts[i][j];
        }

        REP(j, 0, C) {
            max_col[j] = gifts[0][j];
            REP(i, 1, R)
                if(gifts[i][j] > max_col[j])
                    max_col[j] = gifts[i][j];
        }

        bool ok = false;
        int ans = -1;

        REP(i, 0, R) {
            REP(j, 0, C) {
                if(min_row[i] == max_col[j]) {
                    ans = min_row[i];
                    ok = true;
                    break;
                }
            }
            if(ok) break;
        }

        if(!ok) puts("GUESS");
        else printf("%d\n", ans);
    }
}

