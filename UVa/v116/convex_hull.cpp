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


int compareTo(double x, double y, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

////////////////////////////////////////////////////////////////////////////////

double sqr(double v) {
    return v*v;
}

struct point {
    int64 x, y;

    point(int64 a = 0, int64 b = 0) : x(a), y(b) {}
    ~point() {}

    bool operator=(const point& a) {
        x = a.x;
        y = a.y;
    }

    double dist(const point& p) const {
        double cc = sqr(p.x - x) + sqr(p.y - y);
        return sqrt(cc);
    }

    bool operator==(const point& a) const {
        return (x == a.x) && (y == a.y);
    }

} first_point;


const int MAXPOLY = 100000 + 10;

struct polygon {
    int n;
    point p[MAXPOLY];
};


double signed_triangle_area(const point& a, const point& b, const point& c) {
    return ( (a.x * b.y - a.y * b.x + a.y * c.x
              - a.x * c.y + b.x * c.y - c.x * b.y ) / 2.0 );
}

bool ccw(const point& a, const point& b, const point& c) {
    return (signed_triangle_area(a, b, c) > EPS);
}

bool cw(const point& a, const point& b, const point& c) {
    return (signed_triangle_area(a, b, c) < EPS);
}

bool collinear(const point& a, const point& b, const point& c) {
    return (fabs(signed_triangle_area(a, b, c)) <= EPS);
}

double dist(const point& a, const point& b) {
    double xx, yy, cc;
    xx = (a.x - b.x);
    yy = (a.y - b.y);
    xx *= xx;
    yy *= yy;
    cc = xx + yy;
    return sqrt(cc);
}

bool smaller_angle(const point& p1, const point& p2) {
    if (ccw(first_point, p1, p2)) {
        //fprintf(stderr, "p1 ccw\n");
        return true;
    }

    // All getting here!
    if (collinear(first_point, p1, p2)) {
        /*
        if (dist(first_point, p1) <= dist(first_point, p2))
            return true;
        else
            return false;
        */
        if (first_point.x == p1.x && first_point.x == p2.x) {
            return p1.y > p2.y;
        } else if (first_point.y == p1.y && first_point.y == p2.y) {
            return p1.x < p2.x;
        } else {
            return false;
        }
    }

    //fprintf(stderr, "p1 = (%d, %d) p2 = (%d, %d)\n", p1.x, p1.y, p2.x, p2.y);

    return false;
}


int main() {
    int T, N;
    scanf("%d", &T);

    while(T--) {
        scanf("%d", &N);

        //point poly[N + 10];
        vector<point> poly;

        int count = 0;
        REP(i, 0, N) {
            int64 x, y;
            char c;
            scanf("%lld%lld %c", &x, &y, &c);
            if(c == 'Y') {
                //poly[count++] = point(x, y);
                poly.push_back( point(x, y) );
                count++;
            }
        }

        first_point = poly[0];
        int best_i = 0;

        REP(i, 1, count) {
            if (poly[i].x < first_point.x ||
                (poly[i].x == first_point.x && poly[i].y < first_point.y)) {
                first_point = poly[i];
                best_i = i;
            }
        }

        //D(count);
        swap(poly[0], poly[best_i]);
        D(poly[0].x); D(poly[0].y);

        sort(poly.begin()+1, poly.end(), smaller_angle);

        printf("%d\n", count);

        REP(i, 0, count) {
            printf("%lld %lld\n", poly[i].x, poly[i].y);
        }
    }
}

