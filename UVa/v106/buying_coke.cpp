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

int n, total;
int dp[161][161][61]; // [cokes][fives][tens]

int solve(int i, int fives, int tens) {
    if(i == 0) return dp[i][fives][tens] = 0;

    int& r = dp[i][fives][tens];

    if(r == -1) {
        int ones = total - 8 * (n - i) - 5 * fives - 10 * tens;
        r = INF;

        if(ones >= 8) r = min(r, 8 + solve(i-1, fives, tens)); // user just ones
        if(ones >= 3 && fives >= 1) r = min(r, 4 + solve(i-1, fives-1, tens));
        if(ones >= 3 && tens >= 1) r = min(r, 4 + solve(i-1, fives+1, tens-1));
        if(fives >= 2) r = min(r, 2 + solve(i-1, fives-2, tens));
        if(tens >= 1) r = min(r, 1 + solve(i-1, fives, tens-1));
    }

    return r;
}

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int ones, fives, tens;
        scanf("%d%d%d%d", &n, &ones, &fives, &tens);

        total = ones + 5 * fives + 10 * tens;
        memset(dp, -1, sizeof dp);

        printf("%d\n", solve(n, fives, tens));
    }

    return 0;
}

