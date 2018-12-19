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

const double earth_radius = 6440;
const double pi = acos(-1.0);

inline double deg_to_rad(double d) {
    return d * pi / 180.0;
}

int main() {
    ios_base::sync_with_stdio(false);

    int s, a;
    string unit;

    while(cin >> s >> a >> unit) {
        double r = earth_radius + s;
        double d = a;

        if(a > 180)
            d = 360 - a;

        if(unit == "min") d /= 60.0;

        double circumference = 2 * r * pi;

        double arc = circumference * d / 360.0;

        double chord = 2 * r * sin(deg_to_rad(d) / 2.0);

        cout.precision(6);
        cout.setf(ios::fixed);

        cout << arc << " " << chord << endl;
    }
}

