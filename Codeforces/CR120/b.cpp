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

#define D(x) cerr << #x << " = " << x << endl;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

using namespace std;

double sqr(double x) {
    return x*x;
}

double dist(int x1, int y1, int x2, int y2) {
    return sqrt(sqr(x2 - x1) + sqr(y2 - y1));
}

int main() {
    ios_base::sync_with_stdio(false);
    int r1, r2, x1, x2, y1, y2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    double d = dist(x1, y1, x2, y2);
    double ans = 0.0;
    D(d);
    if(d < r1)
        ans = r1 - d - r2;
    else if(d < r2)
        ans = r2 - d - r1;
    else if(d > r1 + r2)
        ans = d - r1 - r2;

    cout << setprecision(15) << fixed;
    cout << (ans / 2.) << endl;
}

