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
    int n, m, k, A, B, r1, p1, p2, x;
    r1 = p1 = -1, p2 = INF;
    cin >> n;

    REP(i, 0, n) cin >> x, r1 = max(r1, x);

    cin >> m;

    REP(i, 0, m) cin >> x, p1 = max(p1, x);

    cin >> k;

    REP(i, 0, k) cin >> x, p2 = min(p2, x);

    cin >> A >> B;
    double ratio = 0.0;

    ratio = (p1 * double(r1 * r1) * B) / double(A * p2 + B * p1);

    cout.precision(12);
    cout.setf(ios::fixed);
    cout << sqrt(ratio) << endl;
}

