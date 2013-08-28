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
#include <set>
#include <map>
#include <algorithm>

#define D(x) cerr << #x << " = " << x << endl
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

using namespace std;

const int MAXN = 1000000 + 10;
int n, m, x[MAXN], t[MAXN], T[MAXN], cost[MAXN];

bool can_bus(int x) {
    REP(i, 0, n) {
        int childs = m / x;
        D(childs);
        if(t[i] + childs > T[i]) return false;
        childs = m % x;
        if(t[i] + childs > T[i]) return false;
    }
    return true;
}

int solve_bus() {
    int lo = 0, hi = m;

    while(lo < hi) {
        int mid = lo + (hi - lo) / 2;
        D(mid);
        bool can = can_bus(mid);
        D(can);

        if(can) hi = mid;
        else lo = mid+1;
    }
    return lo;
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    REP(i, 0, n) cin >> t[i] >> T[i] >> x[i] >> cost[i];

    cout << solve_bus() << endl;
}

