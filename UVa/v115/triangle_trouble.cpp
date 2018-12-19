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

// Problem: 11579 - Triangle Trouble
// Algorithm: Geometry, triangle area from its sides. Sorting

const int MAXN = 1e4 + 10;

double sides[MAXN];

double area(double a, double b, double c) {
    if(a + b < c || a + c < b || b + c < a)
        return 0;

    double s = a + b + c; // semiperimeter;
    s /= 2;

    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
    int t; scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        REP(i, 0, n)
            scanf("%lf", &sides[i]);

        sort(sides, sides + n);

        double ans = 0.0;
        for(int i = n-1; i >= 2; i--)
            ans = max(ans, area(sides[i], sides[i-1], sides[i-2]));

        printf("%.2lf\n", ans);
    }
}

