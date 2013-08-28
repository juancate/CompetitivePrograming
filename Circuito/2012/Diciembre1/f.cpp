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

struct point {
    int x, y;
    point(int _x = 0, int _y = 0) {
        x = _x, y = _y;
    }
};

struct circle {
    int x, y, r;
    circle(int _x = 0, int _y = 0, int _r = 0) {
        x = _x, y = _y, r = _r;
    }
};

inline int sqr(int x) {
    return x*x;
}

bool inCircle(circle c, point p) {
    return (sqr(c.x - p.x) + sqr(c.y - p.y) <= sqr(c.r));
}

bool inRectangle(point p1, point p2, point p) {
    return (p1.x <= p.x && p.x <= p2.x && p1.y <= p.y && p.y <= p2.y);
}

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    while(cin >> n) {
        vector<circle> circles;
        vector< pair<point, point> > rectangles;

        for(int i = 0; i < n; i++) {
            string s; cin >> s;
            if(s == "rectangle") {
                int x1, y1, x2, y2;
                cin >> x1 >> y1 >> x2 >> y2;
                rectangles.push_back( make_pair(point(x1, y1), point(x2, y2)) );
            }
            else {
                int x, y, r;
                cin >> x >> y >> r;
                circles.push_back(circle(x, y, r));
            }
        }

        int m;
        cin >> m;

        for(int i = 0; i < m; i++) {
            point p;
            cin >> p.x >> p.y;
            int sum = 0;
            for(int i = 0; i < circles.size(); i++) {
                sum += inCircle(circles[i], p);
            }
            for(int i = 0; i < rectangles.size(); i++) {
                sum += inRectangle(rectangles[i].first, rectangles[i].second, p);
            }
            cout << sum << endl;
        }
    }
}

