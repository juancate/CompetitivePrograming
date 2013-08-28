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

int compareTo(double x, double y, double tol = EPS) {
    return (x <= y + tol)? (x + tol < y)? -1 : 0 : 1;
}

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int fair_coins = 0, n;
        scanf("%d", &n);
        REP(i, 0, n) {
            double c;
            scanf("%lf", &c);
            if(compareTo(c, 0.5) == 0)
                fair_coins++;
        }

        int64 ans = (1LL << (n - fair_coins)) * ((1LL << fair_coins) - 1);
        printf("%lld\n", ans);
    }
}

