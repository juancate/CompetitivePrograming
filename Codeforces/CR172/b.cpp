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
#include <set>
#include <map>
#include <algorithm>

#define D(x) cerr << #x << " = " << x << endl
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

using namespace std;
int compareTo(double x, double y, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int search(int x, int y, int b) {
    int lo = 0, hi = INF;

    double xy = (double)x / (double)y;

    while(lo < hi) {
        int mid = lo + (hi - lo) / 2;
        double curr = b*xy - mid;
        if(compareTo(curr, xy) <= 0)
            hi = mid;
        else
            lo = mid+1;
    }
    return lo;
}

int main() {
    ios_base::sync_with_stdio(false);
    int x, y, n;
    cin >> x >> y >> n;
    if(n >= y) {
        cout << x << '/' << y << endl;
        return 0;
    }

    double xy = (double)x / (double)y;
    double ans = xy;
    int aa = x, bb = y;

    for(int b = 1; b <= n; b++) {
        int m = search(x, y, b);
        D(m);
        int a = b*x / y - m;
        double ab = (double)a / (double)b;
        D(a); D(b);
        if(fabs(xy-ab) < ans) {
            aa = a; bb = b;
        }
    }
    cout << aa << '/' << bb << endl;

    return 0;
}

