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

int main() {
    ios_base::sync_with_stdio(false);
    int x, t, a, b, da, db;
    cin >> x >> t >> a >> b >> da >> db;

    if(x == 0) {
        cout << "YES\n";
        return 0;
    }

    bool ans = false;
    int ta = a, tb;
    REP(i, 0, t) {
        tb = b;
        REP(i, 0, t) {
            ans = (ta == x || tb == x || ta + tb == x);
            tb -= db;
            if(ans) break;
        }
        ta -= da;
        if(ans) break;
    }

    if(ans) cout << "YES\n";
    else cout << "NO\n";
}

