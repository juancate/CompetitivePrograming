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

const int maxn = 201;

struct point {
    double x, y;
    point(double _x = 0, double _y = 0) {
        x = _x; y = _y;
    }
} poly[maxn];

inline double sqr(double x) {
    return x*x;
}

bool circle2PtsRad(point p1, point p2, double r, point* c) {
    double d2 = sqr(p1.x - p2.x) + sqr(p1.y - p2.y);

    double det = sqr(r) / d2 - 0.25;

    if(det < 0.0) return false;
    double h = sqrt(det);

    c->x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
    c->y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
    return true;
}

bool in_circle(point c, point a, double r) {
    double v = sqr(a.x - c.x) + sqr(a.y - c.y);
    return compareTo(v, sqr(r)) <= 0;
}

char line[1024];

int main() {
    int t;
    sscanf(gets(line), "%d", &t);
    gets(line);

    while(t--) {
        int n = 0;
        while(gets(line) && strlen(line)) {
            sscanf(line, "%lf%lf", &poly[n].x, &poly[n].y);
            n++;
        }

        double r = 2.5;
        int ans = 1;
        point center;

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(circle2PtsRad(poly[i], poly[j], r, &center)) {
                    int cnt = 0;

                    for(int k = 0; k < n; k++) {
                        if(in_circle(center, poly[k], r))
                            cnt++;
                    }

                    ans = max(ans, cnt);
                }

                if(circle2PtsRad(poly[j], poly[i], r, &center)) {
                    int cnt = 0;

                    for(int k = 0; k < n; k++) {
                        if(in_circle(center, poly[k], r))
                            cnt++;
                    }

                    ans = max(ans, cnt);
                }
            }
        }
        printf("%d\n", ans);
        if(t) puts("");
    }
}

