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

template<typename T,typename U> inline
std::ostream& operator<<(std::ostream& os, const pair<T,U>& z){
    return ( os << "(" << z.first << ", " << z.second << ",)" );
}
template<typename T> inline
std::ostream& operator<<(std::ostream& os, const vector<T>& z){
    os << "[ ";
    REP(i,0,z.size())os << z[i] << ", " ;
    return ( os << "]" << endl);
}
template<typename T> inline
std::ostream& operator<<(std::ostream& os, const set<T>& z){
    os << "set( ";
    FOREACH(p,z)os << (*p) << ", " ;
    return ( os << ")" << endl);
}
template<typename T,typename U> inline
std::ostream& operator<<(std::ostream& os, const map<T,U>& z){
    os << "{ ";
    FOREACH(p,z)os << (p->first) << ": " << (p->second) << ", " ;
    return ( os << "}" << endl);
}

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

// Problem: 3581 - Doors and Penguins (LiveArchive)
// Topic: Geometry - Convex Hull (Graham), Line segment, intersection

double sqr(double v) {
    return v*v;
}

struct Point {
    int x, y;

    Point(int a = 0, int b = 0) : x(a), y(b) {}
    ~Point() {}

    bool operator=(const Point& a) {
        x = a.x;
        y = a.y;
    }

    double dist(const Point& p) const {
        double cc = sqr(p.x - x) + sqr(p.y - y);
        return sqrt(cc);
    }
} start;

enum {CCW, CW, CNEITHER};

int ccw(const Point& a, const Point& b, const Point& c) {
    // if counter-clockwise left turn
    // if clockwise returns right turn (ignore)
    // if collinear returns CNEITHER
    int dx1 = b.x - a.x;
    int dx2 = c.x - b.x;
    int dy1 = b.y - a.y;
    int dy2 = c.y - b.y;
    int t1 = dy2 * dx1;
    int t2 = dy1 * dx2;

    if (t1 > t2) {
        return CCW;
    }

    if (t1 == t2) {
        if (dx1 * dx2 < 0 || dy1 * dy2 < 0) {
            if (dx1*dx1 + dy1*dy1 >= dx2*dx2 + dy2*dy2) {
                return CNEITHER;
            } else {
                return CW;
            }
        } else {
            return CCW;
        }
    }

    return CW;
}

bool cmp(const Point& p1, const Point& p2) {
    return (ccw(start, p1, p2) == CCW);
}

struct ConvexHull {
    vector<Point> hull;
    int count;

    ConvexHull() {
        count = 0;
        hull.clear();
    }

    Point operator[](int i) const {
        return hull[i];
    }

    int size() const {
        return count;
    }

    void calculate(vector<Point>& polygon) {
        int n = polygon.size();
        hull.clear();
        hull.resize(n);

        if(n == 1) {
            hull[0] = polygon[0];
            return;
        }

        // Find start: min y and then min x
        start = polygon[0];
        int best_i = 0;

        for(int i = 1; i < n; i++) {
            if(polygon[i].y < start.y || (polygon[i].y == start.y && polygon[i].x < start.x)) {
                start = polygon[i];
                best_i = i;
            }
        }

        swap(polygon[best_i], polygon[0]);

        // sort points according to ccw
        sort(polygon.begin(), polygon.end(), cmp);

        // Calculate convex hull
        count = 0;
        hull[count] = polygon[count]; count++;
        hull[count] = polygon[count]; count++;

        for(int i = 2; i < n; i++) {
            while(count > 1 && ccw(hull[count-2], hull[count-1], polygon[i]) == CW) {
                count--;
            }
            hull[count++] = polygon[i];
        }
    }
};

int direction(Point p1, Point p2, Point p3) {
    int x1 = p3.x - p1.x;
    int y1 = p3.y - p1.y;
    int x2 = p2.x - p1.x;
    int y2 = p2.y - p1.y;
    return x1 * y2 - x2 * y1;
}

bool on_segment(Point p1, Point p2, Point p3) {
    return ((p1.x <= p3.x && p3.x <= p2.x) || (p2.x <= p3.x && p3.x <= p1.x)) &&
        ((p1.y <= p3.y && p3.y <= p2.y) || (p2.y <= p3.y && p3.y <= p1.y));
}

bool intersect(Point a1, Point a2, Point b1, Point b2) {
    int d1 = direction(b1, b2, a1);
    int d2 = direction(b1, b2, a2);
    int d3 = direction(a1, a2, b1);
    int d4 = direction(a1, a2, b2);

    if (((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) &&
        ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0))) {
        return true;
    } else {
        return (d1 == 0 && on_segment(b1, b2, a1)) ||
            (d2 == 0 && on_segment(b1, b2, a2)) ||
            (d3 == 0 && on_segment(a1, a2, b1)) ||
            (d4 == 0 && on_segment(a1, a2, b2));
    }
}

bool point_in_poly(const vector<Point>& poly, const int& n, const Point& p) {
    // check if the point is one vertex
    for (int i = 0; i < n; i++) {
        if (p.x == poly[i].x && p.y == poly[i].y) {
            return true;
        }
    }

    // check on the boundary
    for (int i = 0; i < n-1; i++) {
        if ( ccw(poly[i], poly[i+1], p) == CNEITHER ){
            return true;
        }
    }

    if ( ccw(poly[n-1], poly[0], p) == CNEITHER ) {
        return true;
    }

    bool c = false;

    for (int i = 0, j = n-1; i < n; j = i++) {
        if (( (poly[i].y <= p.y && p.y < poly[j].y) ||
              (poly[j].y <= p.y && p.y < poly[i].y)) &&
            ( (poly[j].y >= poly[i].y &&
               (p.x - poly[i].x) * (poly[j].y-poly[i].y) <
               (poly[j].x - poly[i].x) * (p.y - poly[i].y)) ||
              (poly[j].y < poly[i].y &&
                           (p.x - poly[i].x) * (poly[j].y-poly[i].y) >
               (poly[j].x - poly[i].x) * (p.y - poly[i].y))))
            c = !c;
    }

    return false;
}

bool intersect_hull(const ConvexHull& h1, const ConvexHull& h2) {
    int n = h1.size();
    int m = h2.size();

    for (int i = 0; i < n; i++) {
        if (point_in_poly(h1.hull, h1.size(), h2[i])) {
            return true;
        }
    }

    for (int i = 0; i < m; i++) {
        if (point_in_poly(h2.hull, h2.size(), h1[i])) {
            return true;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (intersect(h1[i], h1[(i+1) % n], h2[j], h2[(j+1) % m])) {
                return true;
            }
        }
    }
    return false;
}

void add_points(vector<Point>& p, int x1, int y1, int x2, int y2, int i) {
    p[i].x = x1; p[i++].y = y1;
    p[i].x = x1; p[i++].y = y2;
    p[i].x = x2; p[i++].y = y1;
    p[i].x = x2; p[i++].y = y2;
}

int main() {
    int D, P, x1, y1, x2, y2, case_num = 1;

    while(~scanf("%d%d", &D, &P) && (D|P)) {
        vector<Point> doors(4*D), penguins(4*P);

        REP(i, 0, D) {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            add_points(doors, x1, y1, x2, y2, i*4);
        }

        REP(i, 0, P) {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            add_points(penguins, x1, y1, x2, y2, i*4);
        }

        ConvexHull hull_doors, hull_penguins;
        hull_doors.calculate(doors);
        hull_penguins.calculate(penguins);

        if(case_num > 1) puts("");
        printf("Case %d: It is ", case_num++);

        if(intersect_hull(hull_doors, hull_penguins)) printf("not ");

        puts("possible to separate the two groups of vendors.");
    }
}

