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


int main() {
    int t; scanf("%d", &t);

    REP(case_id, 1, t+1) {
        int n; scanf("%d", &n);

        vector<int> height(n), width(n);
        REP(i, 0, n) scanf("%d", &height[i]);
        REP(i, 0, n) scanf("%d", &width[i]);

        vector<int> dp(n);
        REP(i, 0, n) dp[i] = width[i];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(height[j] < height[i])
                    dp[i] = max(dp[i], width[i] + dp[j]);
            }
        }

        int inc = *max_element(ALL(dp));

        REP(i, 0, n) {
            height[i] = -height[i];
            dp[i] = width[i];
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(height[j] < height[i])
                    dp[i] = max(dp[i], width[i] + dp[j]);
            }
        }

        int dec = *max_element(ALL(dp));

        printf("Case %d. ", case_id);
        if(inc >= dec)
            printf("Increasing (%d). Decreasing (%d).\n", inc, dec);
        else
            printf("Decreasing (%d). Increasing (%d).\n", dec, inc);
    }
}

