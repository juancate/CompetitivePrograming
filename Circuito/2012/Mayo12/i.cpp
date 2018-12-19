#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>

#define D(x) cerr << #x " = " << x << endl;
#define REP(i,a,n) for(int i=(a); i < (int)(n), i++)

using namespace std;

const int INF = (int)(1e9);
const double EPS = 1e-13;

double sqr(double x) {
    return x*x;
}

struct Point {
	int x, y;

    Point(int a, int b) : x(a), y(b) {}
    Point() {}

    double dist(const Point& p) const {
        double cc = sqr(p.x - x) + sqr(p.y - y);
        return sqrt(cc);
    }
} a, b, p1, p2;

// solve system ecuation
// A-B segment
// C-D segment
Point intersect(const Point & A, const Point & B, const Point & C, const Point & D) {
    double a, b, c, d, rx, ry, det, s, t, x, y;
    a = (B.x - A.x); // R'
    b = (C.x - D.x); // R
    c = (B.y - A.y);
    d = (C.y - D.y);

    rx = C.x - A.x;
    ry = C.y - A.y;

    det = a*d - b*c;
    // parallel lines
    if(fabs(det) < EPS) return Point(-INF, -INF); // Not valid det = 0

    s = (rx * d - b * ry) / det;
    t = (a * ry - rx * c) / det;

    // check if s, t are in [0,1] for an open line segment
    // if not they do not intersect
    if(s < 0.0 or s > 1.0 or t < 0.0 or t > 1.0) return Point(-INF, -INF);

    // use s or t in any parametric ecuation
    x = A.x + (B.x - A.x) * s;
    y = A.y + (B.y - A.y) * s;

    return Point(x, y);
}


bool in_segment() {
    Point c = intersect(a, b, p1, p2);
    return (c.x == -INF and c.y == -INF);
}

int main() {
    int cnt = 1;
    while(~scanf("%d%d%d%d", &a.x, &a.y, &b.x, &b.y) and (a.x|a.y|b.x|b.y) != 0) {
        scanf("%d%d%d%d", &p1.x, &p1.y, &p2.x, &p2.y);

        double ans = 0.0;

        if(!in_segment()) {
            ans = min(a.dist(p1) + p1.dist(b), a.dist(p2) + p2.dist(b));
        } else {
            ans = a.dist(b);
        }

        ans = ans / 2.;
        printf("Case %d: %.3lf\n", cnt++, ans);
    }
}
