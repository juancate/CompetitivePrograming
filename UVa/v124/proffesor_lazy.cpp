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


int main() {
    int64 a, b, n;

    while(~scanf("%lld%lld%lld", &a, &b, &n) && (n|a|b)) {
        n %= 5;

        int64 ans = a;

        if(n == 1) ans = b;
        if(n == 2) ans = (1 + b) / a;
        if(n == 3) ans = (1 + a + b) / (a * b);
        if(n == 4) ans = (1 + a) / b;

        printf("%lld\n", ans);
    }
}

