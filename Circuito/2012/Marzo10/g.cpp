#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>

#define D(x) cerr << #x << " = " << (x) << endl

#define INF 1<<30
#define EPS 1e-13

using namespace std;

// Topic - Geometry: Line parametric, intersection of lines, polygon area, determinant,
// system ecuation, vectors.

double sqr(double v) {
    return v*v;
}

struct Point {
    double x, y;

    Point(double a, double b) : x(a), y(b) {}
    Point() {}

    double dist(const Point& p) const {
        double cc = sqr(p.x - x) + sqr(p.y - y);
        return sqrt(cc);
    }
};

Point midPoint(const Point & a, const Point & b) {
    Point c;
    c.x = (a.x + b.x) * .5;
    c.y = (a.y + b.y) * .5;
    return c;
}

// solve system ecuation
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
    // if not they do not intersects
    if(s < 0.0 or s > 1.0 or t < 0.0 or t > 1.0) return Point(-INF, -INF);

    // use s or t in any parametric ecuation
    x = A.x + (B.x - A.x) * s;
    y = A.y + (B.y - A.y) * s;

    return Point(x, y);
}


double triangleArea(const Point & a, const Point & b, const Point & c) {
    // Polygon Area formula
    double A = fabs(a.x*b.y - b.x*a.y + b.x*c.y - c.x*b.y + c.x*a.y - a.x*c.y) * .5;
    return A;
    // Triangle area of 3 points in the cartesian plane
    /*
      double dx1 = a.x - b.x;
      double dy1 = b.y - a.y;
      double dx2 = a.x - c.x;
      double dy2 = c.y - a.y;
      double A = fabs(dx2 * dy1 - dx1 * dy2) * .5;
      return A;
    */
}

double polygonArea(const Point & a, const Point & b, const Point & c, const Point & d) {
    // Polygon Area formula
    double A = (a.x*b.y - b.x*a.y + b.x*c.y - c.x*b.y + c.x*d.y - d.x*c.y);
    A = fabs(A + (d.x*a.y - a.x*d.y));
    return A * .5;
    //return triangleArea(a, b, c) + triangleArea(a, c, d);
}

int main() {
    int T;
    scanf("%d", &T);

	while(T--) {
        Point A, B, C, D, Am, Bm, Cm, Dm;
        int id;
        A.x = A.y = B.y = 0.0;
        scanf("%d %lf %lf %lf %lf %lf", &id, &B.x, &C.x, &C.y, &D.x, &D.y);

        Am = midPoint(C, B); Bm = midPoint(C, D);
        Cm = midPoint(D, A); Dm = midPoint(A, B);

        Point Ap, Bp, Cp, Dp;
        Ap = intersect(A, Am, B, Bm);
        Bp = intersect(B, Bm, C, Cm);
        Cp = intersect(C, Cm, D, Dm);
        Dp = intersect(D, Dm, A, Am);

        double al = triangleArea(A, Ap, B) / 160.0;
        double bob = triangleArea(B, Bp, C) / 160.0;
        double chas = triangleArea(C, Cp, D) / 160.0;
        double dave = triangleArea(D, Dp, A) / 160.0;

        double emily = polygonArea(Ap, Bp, Cp, Dp) / 160.0;
        double peri = (Ap.dist(Bp) + Bp.dist(Cp) + Cp.dist(Dp) + Dp.dist(Ap)) * 16.5;
        peri = ceil(peri);

        printf("%d %.3lf %.3lf %.3lf %.3lf %.3lf %.0lf\n",id, al, bob, chas, dave, emily, peri);
	}

	return 0;
}
