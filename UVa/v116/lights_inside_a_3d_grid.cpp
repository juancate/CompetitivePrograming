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

void mul(double* ans, double* a) {
    double ret[2];

    ret[0] = a[0] * ans[0] + a[1] * ans[1];
    ret[1] = a[1] * ans[0] + a[0] * ans[1];

    ans[0] = ret[0];
    ans[1] = ret[1];
}

void pow(double* a, int p) {
    double ans[2];

    if(p == 0) {
        a[0] = 0; a[1] = 0;
        return;
    }

    p--;
    ans[0] = a[0]; ans[1] = a[1];

    while(p > 0) {
        if(p & 1) mul(ans, a);
        mul(a, a);
        p >>= 1;
    }

    a[0] = ans[0], a[1] = ans[1];
}



const int maxn = 111;

int n, m, p, t;
int cnt[3][maxn];
double probability[maxn][maxn][maxn];

void init(int dimension, int sz) {
    for(int i = 1; i <= sz; i++) {
        for(int j = 1; j <= sz; j++) {
            for(int k = 1; k <= sz; k++) {
                if(min(i,j) <= k && k <= max(i, j))
                    cnt[dimension][k]++;
            }
        }
    }
}

int main() {
    int cases; scanf("%d", &cases);

    double mat[2];

    REP(cc, 1, cases+1) {
        scanf("%d%d%d%d", &n, &m, &p, &t);

        memset(cnt, 0, sizeof(cnt));
        init(0, n); init(1, m); init(2, p); // x, y, z

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                for(int k = 1; k <= p; k++) {
                    probability[i][j][k] = (cnt[0][i] / (1. * n * n));
                    probability[i][j][k] *= (cnt[1][j] / (1. * m * m));
                    probability[i][j][k] *= (cnt[2][k] / (1. * p * p));
                }
            }
        }

        double ans = 0.0;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                for(int k = 1; k <= p; k++) {
                    double current_probability = probability[i][j][k];

                    mat[0] = 1 - current_probability;
                    mat[1] = current_probability;

                    pow(mat, t);
                    ans += mat[1];
                }
            }
        }

        printf("Case %d: %.10lf\n", cc, ans);
    }
}

