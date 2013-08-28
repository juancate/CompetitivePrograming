#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
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

#define INF 1<<30
#define EPS 1e-13

int compareTo(double x, double y, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

using namespace std;

double sqr(double v) {
    return v*v;
}

struct Point {
    double x, y;

    Point(double a = 0, double b = 0) : x(a), y(b) {}
    ~Point() {}

    bool operator=(const Point& a) {
        x = a.x;
        y = a.y;
    }

    bool operator==(const Point& a) const {
        return (x == a.x) && (y == a.y);
    }

    Point operator-(const Point& a) const {
        return Point(x - a.x, y - a.y);
    }

    double operator*(Point B) const {
        double dot = x * B.x + y * B.y;
        return dot;
    }

    double operator^(Point B) const {
        double cross = x * B.y - y * B.x;
        return cross;
    }

    bool operator<(const Point& a) const {
        int t = compareTo(x, a.x, 0);
        if(t == 0) {
            t = compareTo(y, a.y, 0);
            return t < 0;
        }
        return t < 0;
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
    int x = compareTo((a - c) ^ (b - c), 0.0, EPS);
    if(x == 0) return CNEITHER;
    if(x < 0) return CCW;
    return CW;
}

bool cmp(const Point& p1, const Point& p2) {
    Point p = p1 - start;
    Point q = p2 - start;

    double r = p ^ q;
    int comp = compareTo(r, 0.0, EPS);
    if(comp != 0) return (comp > 0);
    return compareTo(p * p, q * q, EPS) < 0;
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
            count = 1;
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

        int k;

        for (k = n - 2; k >= 0 && ccw(polygon[0], polygon[n - 1], polygon[k]) == CNEITHER; k--);
        int mid = (n + k + 1) / 2;
        for (int h = k + 1; h < mid; h++) {
            swap(polygon[n - h + k], polygon[h]);
        }

        for(int i = 0; i <= n; i++) {
            if(i == n && count == 2) break;
            while(count > 1 && ccw(hull[count-1], hull[count-2], polygon[i % n]) == CW) {
                count--;
            }
            if(i == n) break;
            hull[count++] = polygon[i];
        }
    }
};

double polygonArea(const ConvexHull& a) {
    double area = 0.0;

    for(int i = 1; i + 1 < a.size(); i++) {
        area += (a[i] - a[0]) ^ (a[i + 1] - a[0]);
    }
    return area * .5;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n;
    vector<Point> A(n);

    REP(i,0,n) cin >> A[i].x >> A[i].y;

    cin >> m;
    vector<Point> B(m);

    REP(i,0,m) cin >> B[i].x >> B[i].y;

    vector<Point> AB;
    REP(i, 0, n) AB.push_back(A[i]);
    REP(i, 0, m) AB.push_back(B[i]);

    ConvexHull hull;
    hull.calculate(AB);

    set<Point> point_in_hull;
    REP(i, 0, hull.size()) {
        point_in_hull.insert(hull[i]);
    }

    REP(i, 0, m) {
        if(point_in_hull.count(B[i])) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
}

