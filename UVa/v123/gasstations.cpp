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

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

const int MAXG = 10000 + 10;

int L, G;
pair<int, int> stations[MAXG];
int dp[MAXG];

int main() {
    int x, r;
    while(~scanf("%d%d", &L, &G) && (L|G) != 0) {
        REP(i, 1, G+1) {
            scanf("%d%d", &x, &r);
            stations[i].first = x+r; // pos
            stations[i].second = r+r; // reach
        }
        stations[G+1].first = L;
        stations[G+1].second = 0;

        sort(stations + 1, stations + G + 1);

        dp[0] = 0;

        for(int i = 1; i <= G+1; i++) {
            int best = INF;

            for(int j = i-1; j >= 0; j--) {
                if(stations[i].first - stations[i].second <= stations[j].first)
                    best = min(best, dp[j]);
                else break;
            }

            dp[i] = (best == INF)? INF : best+1;
        }

        if(dp[G+1] < INF)
            printf("%d\n", (G - dp[G+1] + 1));
        else
            puts("-1");
    }
}

