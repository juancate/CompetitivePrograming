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

#define D(x) cout << #x << " = " << (x) << endl;
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
        x = _x; y = _y;
    }

    bool operator<(const point& other) const {
        if(x == other.x)
            return y < other.y;
        return x < other.x;
    }
};

struct line {
    vector<point> P;

    void add(point p) {
        P.push_back(p);
    }

    int size() {
        return (int)P.size();
    }

    bool contains(const point& p) {
        for(int i = 0; i < (int)P.size(); i++)
            if(p.x == P[i].x && p.y == P[i].y)
                return true;
        return false;
    }

    void print() const {
        for(int i = 0; i < (int)P.size(); i++) {
            cout << '(' << setw(4) << P[i].x
                 << ',' << setw(4) << P[i].y << ')';
        }
    }
};

bool exists_point(vector<line>& lines, const point& p, const point& q) {
    int n = (int)lines.size();

    for(int i = 0; i < n; i++) {
        if(lines[i].contains(p) && lines[i].contains(q))
            return true;
    }

    return false;
}

void print(const vector<line>& lines) {
    int n = (int)lines.size();

    if(n == 0) {
        cout << "No lines were found" << endl;
    }
    else {
        cout << "The following lines were found:" << endl;
        for(int i = 0; i < n; i++) {
            lines[i].print();
            cout << endl;
        }
    }
}

int cross(const point& p, const point& q, const point& r) {
    return (r.x - q.x) * (p.y - q.y) - (r.y - q.y) * (p.x - q.x);
}

bool collinear(const point& p, const point& q, const point& r) {
    return cross(p, q, r) == 0;
}

void solve(const vector<point>& P) {
    vector<line> lines;
    int n = (int)P.size();

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(exists_point(lines, P[i], P[j]))
                continue;

            line L;
            L.add(P[i]); L.add(P[j]);

            for(int k = j+1; k < n; k++) {
                if(collinear(P[i], P[j], P[k]))
                    L.add(P[k]);
            }
            if(L.size() > 2)
                lines.push_back(L);
        }
    }
    print(lines);
}

int main() {
#ifdef LOCAL
    freopen("laser_lines.in", "r", stdin);
    freopen("laser_lines.out", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
#endif

    int x, y;
    while(cin >> x >> y) {
        if(x == 0 && y == 0)
            break;

        vector<point> P;
        P.push_back(point(x, y));
        while(cin >> x >> y) {
            if(x == 0 && y == 0)
                break;
            P.push_back(point(x, y));
        }
        sort(P.begin(), P.end());
        solve(P);
    }
}
