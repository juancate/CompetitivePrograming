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

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

int compareTo(double x, double y, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int maxn = 210;

typedef pair<double, double> point;
#define x first
#define y second

const double rr = 2.5 * 2.5;
const double diameter = 2 * 2.5;

int n;
point p[maxn];
char line[maxn];

double pow(double x) {
    return x*x;
}

double calculate_distance(double x, double y) {
    return pow(x) + pow(y);
}

vector<point> calculate_center(const point& a, const point& b, double len) {
    double sqrt_len = sqrt(len);
    point d((b.x - a.x) / sqrt_len, (b.y - a.y) / sqrt_len);

    point pm((a.x + b.x) / 2., (a.y + b.y) / 2.);

    double t = sqrt(rr - len / 4.);

    point pd(-d.y, d.x);

    point c1(pm.x + pd.x * t, pm.y + pd.y * t);

    pd = point(d.y, -d.x);

    point c2(pm.x + pd.x * t, pm.y + pd.y * t);

    vector<point> ret(2);
    ret[0] = c1, ret[1] = c2;
    return ret;
}

bool point_in_circle(const point& center, const point& a) {
    double x = pow(a.x - center.x) + pow(a.y - center.y);

    return compareTo(x, rr) <= 0;
}

int main() {
    int t; scanf("%d\n", &t);

    while(t--) {
        n = 0;

        while(gets(line)) {
            if(strlen(line) == 0)
                break;

            sscanf(line, "%lf%lf", &p[n].x, &p[n].y);
            n++;
        }

        sort(p, p+n);
        int ans = 1;

        for(int i = 1; i < n; i++) {
            for(int j = i-1; j >= 0; j--) {
                double len = calculate_distance(p[i].x - p[j].x, p[i].y - p[j].y);

                if(len > diameter*diameter) continue;

                vector<point> cs = calculate_center(p[i], p[j], len);

                for(int k = 0; k < 2; k++) {
                    int cnt = 0;
                    for(int l = 0; l < n; l++) {
                        if(point_in_circle(cs[k], p[l]))
                            cnt++;
                    }
                    ans = max(ans, cnt);
                }
            }
        }
        printf("%d\n", ans);
    }
}

