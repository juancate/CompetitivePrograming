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

int W, D, A, K;
int p1[10], q1[10], p2[10], q2[10];

double f(double x, double mid) {
    double num1, den1, num2, den2, pot;
    num1 = den1 = num2 = den2 = 0;
    pot = 1;
    for(int i = 0; i <= K; i++) {
        num1 += p1[i] * pot;
        den1 += q1[i] * pot;
        num2 += p2[i] * pot;
        den2 += q2[i] * pot;
        pot *= x;
    }

    double y1 = num1 / den1;
    double y2 = num2 / den2;

    if(mid > y1) return 0;
    if(mid > y2) return y1 - mid;

    return y1 - y2;
}

int main() {
#ifdef LOCAL
    freopen("environment.in", "r", stdin);
    freopen("environment.out", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
#endif

    cout.precision(5);
    cout.setf(ios::fixed);

    while(cin >> W >> D >> A >> K) {
        REP(i,0,K+1) cin >> p1[i];
        REP(i,0,K+1) cin >> q1[i];
        REP(i,0,K+1) cin >> p2[i];
        REP(i,0,K+1) cin >> q2[i];

        double lo = -D, hi = 0;

        for(int i = 0; i < 22; i++) {
            double mid = (lo + hi) / 2.;

            double ini = 0;
            double diff = 1e-3;
            double sum = 0;

            for(; ini+diff < W+EPS; ini += diff) {
                sum += (f(ini, mid) + 4*f(ini + diff/2., mid) + f(ini+diff, mid)) / 6.0;
            }

            if(sum * diff < A)
                hi = mid;
            else
                lo = mid;
        }
        cout << -lo << endl;
    }
}

