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

const double PI = acos(-1.0);

int compareTo(double x, double y, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct point {
    double x, y;
    point(double _x = 0, double _y = 0) {
        x = _x, y = _y;
    }
    bool operator<(point other) {
        if(fabs(x-other.x) < EPS)
            return x < other.x;
        return y < other.y;
    }
};

struct line {
    double a, b, c;
};

inline
double deg_to_rad(double theta) {
    return theta * PI / 180.0;
}

point rotate(point p, double theta) {
    double rad = deg_to_rad(theta);
    return point(p.x * cos(rad) - p.y * sin(rad),
                 p.x * sin(rad) + p.y * cos(rad));
}

void points_to_line(point p1, point p2, line *l) {
    if(fabs(p1.x - p2.x) < EPS) { // check
        l->a = 1.0; l->b = 0.0; l->c = -p1.x;
    }
    else {
        l->a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l->b = 1.0;
        l->c = -(double)(l->a * p1.x) - (l->b * p1.y);
    }
}

bool are_parallel(line l1, line l2) {
    return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS);
}

bool are_same(line l1, line l2) {
    return are_parallel(l1, l2) && (fabs(l1.c - l2.c) < EPS);
}

bool are_intersect(line l1, line l2, point *p) {
    if(are_same(l1, l2)) return false;
    if(are_parallel(l1, l2)) return false;

    p->x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    if(fabs(l1.b) > EPS)
        p->y = - (l1.a * p->x + l1.c) / l1.b;
    else
        p->y = - (l2.a * p->x + l2.c) / l2.b;
    return true;
}

double area(vector<point> P) {
    double result = 0.0, x1, y1, x2, y2;
    for(int i = 0; i < (int)P.size(); i++) {
        x1 = P[i].x; x2 = P[i+1].x;
        y1 = P[i].y; y2 = P[i+1].y;
        result += (x1 * y2 - x2 * y1);
    }
    return fabs(result) / 2.0;
}

double cross(point p, point q, point r) {
    return (r.x - q.x) * (p.y - q.y) - (r.y - q.y) * (p.x - q.x);
}

bool collinear(point p, point q, point r) {
    return fabs(cross(p, q, r)) < EPS;
}

bool ccw(point p, point q, point r) {
    return cross(p, q, r) > 0;
}

bool dist(point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

point pivot;
bool angle_cmp(point a, point b) {
    if(collinear(pivot, a, b))
        return dist(pivot, a) < dist(pivot, b);
    double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
    double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
    return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    vector<point> r1, r2;

    int w, h, t;
    cin >> w >> h >> t;

    cout.precision(20);
    cout.setf(ios::fixed);
    if(t == 180) {
        double ans = (double)w*(double)h;
        cout << ans << endl;
        return 0;
    }

    double xm = w / 2.;
    double ym = h / 2.;

    r1.push_back(point(-xm, -ym));
    r1.push_back(point(-xm, ym));
    r1.push_back(point(xm, ym));
    r1.push_back(point(xm, -ym));

    for(int i = 0; i < r1.size(); i++) {
        r2.push_back(rotate(r1[i], t));
    }
    r1.push_back(r1[0]);
    r2.push_back(r2[0]);

    vector<line> ls1, ls2;

    for(int i = 0; i < r1.size()-1; i++) {
        line l;
        points_to_line(r1[i], r1[i+1], &l);
        ls1.push_back(l);
        points_to_line(r2[i], r2[i+1], &l);
        ls2.push_back(l);
    }

    vector<point> inter;
    vector< pair<double, double> > in;
    for(int i = 0; i < ls1.size(); i++) {
        for(int j = 0; j < ls2.size(); j++) {
            point p;
            if(are_intersect(ls1[i], ls2[j], &p)) {
                if(compareTo(p.x, -xm) >= 0 && compareTo(p.x, xm) <= 0) {
                    if(compareTo(p.y, -ym) >= 0 && compareTo(p.y, ym) <= 0) {
                        in.push_back(make_pair(p.x, p.y));
                    }
                }
            }
        }
    }
    sort(ALL(in));
    int sz = int(unique(ALL(in)) - in.begin());
    in.resize(sz);
    for(int i = 0; i < in.size(); i++) {
        inter.push_back(point(in[i].first, in[i].second));
    }
    pivot = inter[0];
    sort(++inter.begin(), inter.end(), angle_cmp);

    inter.push_back(pivot);
    cout << area(inter) << endl;

    return 0;
}

