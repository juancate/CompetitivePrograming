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
/*
int big_mod(int64 b, int64 p, int m) {
    if(p == 0)
        return 1;

    if(p & 1) {
        return ( (b % m) * ( big_mod(b, p-1, m) ) ) % m;
    }
    int64 c = big_mod(b, p >> 1, m);
    return (c * c) % m;
}
*/
int mod_pow(int64 b, int64 p, int m) {
    int64 res = 1;
    while(p > 0) {
        if(p & 1) res = (res * b) % m;
        b = (b * b) % m;
        p >>= 1;
    }

    return res % m;
}

int main() {
    int64 b, p;
    int m;

    while(~scanf("%lld%lld%d", &b, &p, &m)) {
        //printf("%d\n", big_mod(b, p, m));
        printf("%d\n", mod_pow(b, p, m));
    }
}

