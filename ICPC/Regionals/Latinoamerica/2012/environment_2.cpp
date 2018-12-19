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
const double EPS = 1e-5;

int W, D, A, K, N;
int p1[10], q1[10], p2[10], q2[10];
double h;

inline double f(const double& x, const double& mid) {
    double num1, den1, num2, den2;
    num1 = den1 = num2 = den2 = 0;

    for(int i = K; i >= 0; i--) {
        num1 = num1 * x + p1[i];
        den1 = den1 * x + q1[i];
        num2 = num2 * x + p2[i];
        den2 = den2 * x + q2[i];
    }

    double y1 = num1 / den1;

    if(mid > y1) return 0;

    double y2 = num2 / den2;

    if(mid > y2) return y1 - mid;

    return y1 - y2;
}

inline double eval(const double& mid) {
    double a = 0, b = W;
    double s = 0;
    //double h = (b - a) / N;

    for(int i = 0; i <= N; i++) {
        double x = a + h * i;
        s += f(x, mid) * ((i == 0 || i == N)? 1 : ((i & 1) == 0)? 2 : 4);
    }

    s *= h / 3;
    return s;
}

int main() {
#ifdef LOCAL
    freopen("environment.in", "r", stdin);
    freopen("environment.out", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif

    cout.precision(5);
    cout.setf(ios::fixed);

    while(cin >> W >> D >> A >> K) {
        REP(i,0,K+1) cin >> p1[i];
        REP(i,0,K+1) cin >> q1[i];
        REP(i,0,K+1) cin >> p2[i];
        REP(i,0,K+1) cin >> q2[i];

        double lo = -D, hi = 0;
        N = W * 550;
        h = W / (double)N;

        for(int i = 0; i < 22; i++) {
            double mid = (lo + hi) * .5;

            if(eval(mid) < A)
                hi = mid;
            else
                lo = mid;
        }
        cout << -lo << '\n';
    }
}

