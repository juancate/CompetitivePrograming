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

const int mod = INF + 7;

int64 modpow(int64 base, int exponent) {
    int64 result = 1;

    while(exponent > 0) {
        if(exponent & 1)
            result = (result * base) % mod;

        exponent >>= 1;
        base = (base * base) % mod;
    }

    return result;
}

int main() {
    int t; scanf("%d", &t);
    while(t--) {
        int n; scanf("%d", &n);

        int64 a = n >> 1;
        int64 b = n - a;

        int m1 = 1, m2 = 0;

        if(n & 1) {
            m1 = 0;
            m2 = 1;
            a = b;
        } else {
            b++;
        }

        int64 ans = (modpow(2, b) - modpow(2, m1)) % mod;
        ans += (modpow(2, a) - modpow(2, m2)) % mod;
        ans %= mod;

        printf("%lld\n", ((ans+1) % mod));
    }
}

