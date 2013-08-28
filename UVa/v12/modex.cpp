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

int64 modpow(int64 x, int64 p, int mod) {
    int64 res = 1;

    while(p > 0) {
        if(p & 1) res = (res * x) % mod;
        x = (x * x) % mod;

        p >>= 1;
    }

    return res;
}

int main() {
    int t; scanf("%d", &t);

    while(t--) {
        int x, n;
        int64 y;
        scanf("%d%lld%d", &x, &y, &n);

        printf("%lld\n", modpow(x, y, n));
    }
    scanf("%d", &t);
    return 0;
}

