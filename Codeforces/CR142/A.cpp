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

struct dragon {
    int s, p;

    dragon(int _s = 0, int _p = 0) {
        s = _s; p = _p;
    }

    bool operator<(const dragon& a) const {
        if(s == a.s) return p > a.p;
        return s < a.s;
    }
};

int main() {
    ios_base::sync_with_stdio(false);

    int s, n;
    cin >> s >> n;

    vector<dragon> d(n);

    REP(i, 0, n)
        cin >> d[i].s >> d[i].p;

    sort(ALL(d));

    bool ok = true;

    REP(i, 0, n) {
        if(s <= d[i].s) {
            ok = false;
            break;
        }
        s += d[i].p;
    }

    cout << (ok? "YES" : "NO") << endl;
}

