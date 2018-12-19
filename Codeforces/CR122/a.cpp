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

int memo[60][260];

int solve(int n, int k) {
    if(k < 0 || n < 0) return INF;
    if(k == 0 && n == 0) return 0;
    else if(k == 0 && n != 0) return INF;

    if(memo[n][k] != -1) return memo[n][k];

    memo[n][k] =  min(min(1 + solve(n - 1, k - 2), solve(n - 1, k - 3)),
                      min(solve(n - 1, k - 4), solve(n - 1, k - 5)));
    return memo[n][k];
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    //memset(memo, -1, sizeof(memo));
    REP(i, 0, n+1) REP(j, 0, k+1) memo[i][j] = -1;
    cout << solve(n, k) << endl;
}

