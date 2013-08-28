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

int candies[33], n, sum;
bool dp[641][641];

int diff(int i, int j) {
    return abs(i-j);
}

void process() {
    dp[0][0] = true;
    for(int i = 0; i < n; i++) {
        for(int j = sum; j >= 0; j--) {
            for(int k = sum; k >= 0; k--) {
                if(dp[j][k]) {
                    dp[j + candies[i]][k] = true;
                    dp[j][k + candies[i]] = true;
                }
            }
        }
    }
}

int solve() {
    int best = INF;
    const int limit_i = sum / 3;
    const int limit_j = limit_i * 2;

    for(int i = 0; i <= limit_i; i++) {
        for(int j = 0; j <= limit_j; j++) {
            if(dp[i][j]) {
                best = min(best, diff(i,j) + diff(sum-i-j, j));
            }
        }
    }

    return best;
}

int main() {
    int t;
    scanf("%d", &t);

    for(int case_id = 1; case_id <= t; case_id++) {
        scanf("%d", &n);
        sum = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", &candies[i]);
            sum += candies[i];
        }
        memset(dp, false, sizeof dp);

        process();
        printf("Case %d: %d\n", case_id, solve());
    }
    return 0;
}

