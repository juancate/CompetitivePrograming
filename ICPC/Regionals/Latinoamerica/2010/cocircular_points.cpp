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

int compareTo(double x, double y, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int maxn = 110;

struct point {
    double x, y;

    point(double a = 0, double b = 0) {
        x = a; y = b;
    }
} poly[maxn];

inline double sqr(double x) {
    return x*x;
}

point midPoint(const point & a, const point & b) {
    point c;
    c.x = (a.x + b.x) * .5;
    c.y = (a.y + b.y) * .5;
    return c;
}

bool intersect(const point & A, const point & B, const point & C, const point & D, point& center) {
    double a, b, c, d, rx, ry, det, s, t, x, y;
    a = (B.x - A.x); // R'
    b = (C.x - D.x); // R
    c = (B.y - A.y);
    d = (C.y - D.y);

    rx = C.x - A.x;
    ry = C.y - A.y;

    det = a*d - b*c;
    // parallel lines
    if(fabs(det) < EPS) return false; // Not valid det = 0

    s = (rx * d - b * ry) / det;
    t = (a * ry - rx * c) / det;

    // check if s, t are in [0,1] for an open line segment
    // if not they do not intersects
    if(s < 0.0 or s > 1.0 or t < 0.0 or t > 1.0) return false;

    // use s or t in any parametric ecuation
    x = A.x + (B.x - A.x) * s;
    y = A.y + (B.y - A.y) * s;

    center = point(x, y);
    return true;
}

bool on_perimeter(const point& c, const point& a, const double& rr) {
    double v = sqr(a.x - c.x) + sqr(a.y - c.y);
    return compareTo(v, rr) == 0;
}

int main() {
    int n;
    while(scanf("%d", &n) && n) {
        REP(i, 0, n) {
            int x, y; scanf("%d%d", &x, &y);
            poly[i] = point(x, y);
        }

        if(n <= 2) {
            printf("%d", n);
            continue;
        }

        int ans = 0;
        point center;

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                for(int k = j+1; k < n; k++) {

                    point ab = midPoint(poly[i], poly[j]);
                    point bc = midPoint(poly[j], poly[k]);
                    //point ac = midPoint(poly[k], poly[i]);
                    cerr << "ab = " << ab.x << ", " << ab.y << endl;
                    cerr << "bc = " << bc.x << ", " << bc.y << endl;

                    if(intersect(ab, poly[k], bc, poly[i], center)) {
                        int cnt = 0;
                        //cerr << "center = (" << center.x << ", " << center.y << ")\n";
                        double d = sqr(center.x - poly[i].x) + sqr(center.y - poly[i].y);
                        for(int l = 0; l < n; l++) {
                            if(on_perimeter(center, poly[l], d))
                                cnt++;
                        }

                        ans = max(ans, cnt);
                    }
                }
            }
        }

        printf("%d\n", ans);
    }
}

