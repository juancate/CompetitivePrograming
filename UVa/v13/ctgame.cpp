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
typedef unsigned long long uint64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

const int MAXH = 1000 + 10;
const int MAXW = 1000 + 10;

char board[MAXH];
int64 dp[MAXH][MAXW];
int64 hist[1000100];
stack< pair<int, int> > s;

uint64 calc_histogram(int n) {
    uint64 best = 0;
    int start = 0;

    hist[n] = 0;

    for(int i = 0; i <= n; i++) {
        start = i;

        while(!s.empty() && (hist[i] < s.top().second)) {
            uint64 tmp = (int64)(i - s.top().first) * s.top().second;

            best = max(best, tmp);

            start = s.top().first;
            s.pop();
        }

        s.push( make_pair(start, hist[i]) );
    }

    return best;
}

int main() {
    int K, H, W;
    scanf("%d", &K);
    while (K--) {
        scanf("%d%d", &H, &W);

        REP(i, 0, H) {
            int j = 0;
            REP(j, 0, W) {
                char ch; scanf("\n%c", &ch);

                if(ch == 'R')
                    dp[i][j] = 0;
                else if(ch == 'F')
                    dp[i][j] = 1;
            }
        }

        uint64 ans = 0;

        for(int i = W-2; i >= 0; i--) {
            REP(j, 0, H) {
                if(dp[j][i])
                    dp[j][i] += dp[j][i+1];
            }
        }

        REP(i, 0, W) {
            REP(j, 0, H) {
                hist[j] = dp[j][i];
            }
            ans = max(ans, calc_histogram(H));
        }

        printf("%lld\n", ans * 3);
    }
}

