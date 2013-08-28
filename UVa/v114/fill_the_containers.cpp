#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>

#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

const int MAXN = 1000;

int N, M, vessels[MAXN];

bool can(int64 c) {
    int cnt = 1;
    int64 current = c;

    REP(i, 0, N) {
        if(vessels[i] > c) return false;
        if(current - vessels[i] >= 0) {
            current -= vessels[i];
        } else {
            current = c - vessels[i];
            cnt++;
        }
    }

    return cnt <= M;
}

int64 solve() {
    int64 lo = 0, hi = INFLL;

    while(lo < hi) {
        int64 mid = lo + (hi - lo) / 2;
        if(can(mid)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int main() {
    while(~scanf("%d%d", &N, &M)) {
        REP(i, 0, N) scanf("%d", vessels + i);
        printf("%lld\n", solve());
    }
}

