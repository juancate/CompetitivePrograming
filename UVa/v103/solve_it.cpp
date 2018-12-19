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

#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

int compareTo(double x, double y, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int p, q, r, s, t, u;

double f(double x) {
    double val = p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
    return val;
}

bool can(double x) {
    double val = f(x);
    return compareTo(val, 0.0) <= 0;
}

int main() {
    while(~scanf("%d%d%d%d%d%d", &p, &q, &r, &s, &t, &u)) {
        double lo = 0.0, hi = 1.0;
        for(int i = 0; i < 50; i++) {
            double mid = (lo + hi) / 2.;

            if(can(mid)) hi = mid;
            else lo = mid;
        }
        //fprintf(stderr, "lo = %lf, hi = %lf\n", lo, hi);
        if(f(0) * f(1) > 0) puts("No solution");
        else printf("%.4lf\n", lo);
    }
}

