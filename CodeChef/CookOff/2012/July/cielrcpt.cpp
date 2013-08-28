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

int dp[111111];

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int p;
        scanf("%d", &p);
        memset(dp, 0x3f, sizeof(dp));

        dp[0] = 0;
        for(int i = 0; i <= p; i++) {
            for(int v = 1; v <= 2048; v *= 2)
                dp[v + i] = min(dp[v + i], dp[i] + 1);
        }
        printf("%d\n", dp[p]);
    }
}

