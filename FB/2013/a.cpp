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

const int maxn = 10000;
const int mod = INF + 7;
long long a[maxn];

long long mod_pow(long long x, long long y) {
    long long r = 1, a = x;
    while(y > 0) {
        if(y & 1) r = (r * a) % mod;
        a = (a * a) % mod;
        y /= 2;
    }
    return r;
}

long long mod_inverse(long long x) {
    return mod_pow(x, mod-2);
}

long long mod_division(long long p, long long q) {
    return (p * mod_inverse(q)) % mod;
}

long long comb(long long n, int k) {
    if(k > n) {
        return 0;
    }
    long long p = 1, q = 1;
    for(int i=1; i<=k; i++) {
        q = ( q * i) % mod;
        p = ( p * (n - i + 1) ) % mod;
    }
    return mod_division(p, q);
}

int main() {
    int t;
    scanf("%d", &t);

    for(int case_id = 1; case_id <= t; case_id++) {
        int n, k;
        scanf("%d%d", &n, &k);
        for(int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        sort(a, a+n);
        int64 sum = 0;
        for(int i = n-1; i >= 0; i--) {
            if(i+1 < k) break;
            sum = (sum + (a[i] * comb(i, k-1)) % mod) % mod;
        }
        printf("Case #%d: %lld\n", case_id, sum);
    }

    return 0;
}

