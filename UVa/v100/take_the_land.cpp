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

const int MAXN = 111;

int land[MAXN][MAXN], n, m, v;
int sum[MAXN];

int kadane(int& l, int& r) {
    int max_sum = -INF;
    int current_sum = 0;

    for(int i = 0, j = 0; j < n; j++) {
        current_sum += sum[j];

        if(current_sum > max_sum) {
            l = i, r = j;
            max_sum = current_sum;
        }

        if(current_sum < 0) {
            current_sum = 0;
            i = j+1;
        }
    }

    return max_sum;
}

int main() {
    while(~scanf("%d%d", &m, &n) && (n|m)) {
        REP(i, 0, m) REP(j, 0, n) {
            scanf("%d", &v);
            if(v == 0) land[i][j] = 1;
            else land[i][j] = -100000;
        }

        int ans = -INF, x1, y1, x2, y2;

        REP(i, 0, m) {
            REP(j, 0, n)
                sum[j] = 0;

            REP(j, i, m) {
                REP(k, 0, n)
                    sum[k] += land[j][k];
                int tx, ty;
                int current = kadane(tx, ty);
                if(current > ans) {
                    ans = current;
                    y1 = tx, y2 = ty;
                    x1 = i, x2 = j;
                }
            }
        }

        if(ans < 0) ans = 0;
        printf("%d\n", ans);
    }
}

