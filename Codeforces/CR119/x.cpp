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

#define D(x) cerr << #x << " = " << x << endl;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

using namespace std;

const int MAXN = 4000 + 10;

int a, b, c, n;
int dp[MAXN];

int solve(int x) {
    if(x == 0) return 0;

    if(dp[x] != -1) return dp[x];

    if(x - a >= 0 and solve(x - a)) dp[x] = max(dp[x], 1 + solve(x - a));
    if(x - b >= 0 and solve(x - b)) dp[x] = max(dp[x], 1 + solve(x - b));
    if(x - c >= 0 and solve(x - c)) dp[x] = max(dp[x], 1 + solve(x - c));

    if(x == a or x == b or x == c) dp[x] = max(dp[x], 1);

    return dp[x];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> a >> b >> c;
    memset(dp, -1, sizeof(dp));
    cout << solve(n) << endl;
}
