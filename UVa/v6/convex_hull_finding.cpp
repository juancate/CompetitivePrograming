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
    int x, y;

    point(int a = 0, int b = 0) : x(a), y(b) {}
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


const int MAXPOLY = 600;

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

bool leftlower(const point& p1, const point& p2) {

    if ( p1.y < p2.y ) return true;
    if ( p1.y > p2.y ) return false;

    if ( p1.x < p2.x ) return true;
    if ( p1.x > p2.x ) return false;

    return true;
}

void sort_and_remove_duplicates(point in[], int& n) {
    int i, oldn, hole;

    sort(in, in + n, leftlower);

    oldn = n;
    hole = 1;

    for (i = 1; i < (oldn - 1); i++) {
        if ((in[hole-1].x == in[i].x) && (in[hole-1].y == in[i].y))
            n--;
        else {
            in[hole] = in[i];
            hole++;
        }
    }
    in[hole] = in[oldn-1];
}

bool smaller_angle(const point& p1, const point& p2) {

    if (collinear(first_point, p1, p2)) {
        if (dist(first_point, p1) <= dist(first_point, p2))
            return true;
        else
            return false;
    }

    if(ccw(first_point, p1, p2))
        return true;

    return false; // >
}

void convex_hull(point in[], int n, polygon& hull) {
    int i, top;

    if(n <= 3) {
        for (i = 0; i < n; i++) {
            hull.p[i] = in[i];
        }
        hull.n = n;
        return;
    }

    sort_and_remove_duplicates(in, n);
    first_point = in[0];

    sort(&in[1], &in[n], smaller_angle);

    hull.p[0] = first_point;
    hull.p[1] = in[1];

    in[n] = first_point;
    top = 1;
    i = 2;

    while(i <= n) {
        while (top > 0 && !ccw(hull.p[top-1], hull.p[top], in[i]) )
            top = top-1;
        top++;
        hull.p[top] = in[i];
        i++;
    }

    hull.n = top;
}



int main() {
    int K, N, delim, i, x, y;

    scanf("%d", &K);
    printf("%d\n", K);
    while(K--) {
        scanf("%d", &N);

        point poly[N+10];

        for (i = 0; i < N; i++) {
            scanf("%d%d", &x, &y);
            poly[i].x = x; poly[i].y = y;
        }

        scanf("%d", &delim);

        polygon hull;
        convex_hull(poly, N, hull);

        printf("%d\n", hull.n + 1);
        for (i = 0; i <= hull.n; i++) {
            printf("%d %d\n", hull.p[i].x, hull.p[i].y);
        }

        if(K) printf("%d\n", delim);
    }

    return 0;
}

