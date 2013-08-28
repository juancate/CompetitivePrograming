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

int64 x, y, d;

void extended_euclid(int64 a, int64 b) {
    if(b == 0) {
        x = 1; y = 0; d = a;
        return;
    }

    extended_euclid(b, a % b);
    int64 x1 = y;
    int64 y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}

int main() {
    int t; scanf("%d", &t);
    while(t--) {
        int64 z, k;
        scanf("%lld%lld", &z, &k);
        int64 floor = z / k;
        int64 ceil = floor;
        if(z % k) ceil++;
        extended_euclid(floor, ceil);

        int64 f = z / __gcd(floor, ceil);
        x *= f;
        y *= f;

        printf("%lld %lld\n", x, y);
    }
}

