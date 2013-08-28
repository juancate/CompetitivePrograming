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

#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

const int MAXN = 1000 + 10;

int xx[MAXN], yy[MAXN];
double dist[MAXN][MAXN];

int main() {
    int t, n;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        double max_dist = 0.0;

        for(int i = 0; i < n; i++) {
            scanf("%d%d", &xx[i], &yy[i]);

            for(int j = i-1; j >= 0; j--) {
                dist[i][j] = dist[j][i] = hypot(xx[j] - xx[i], yy[j] - yy[i]);
                max_dist = max(max_dist, dist[i][j]);
            }
        }

        if(n >= 5) {
            printf("%.20lf\n", max_dist);
            continue;
        }

       
    }
}

