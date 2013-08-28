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

const int MAXN = 255;

int g[MAXN][MAXN];

int main() {
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &g[i][j]);
        }
    }
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

    int m;
    scanf("%d", &m);

    for(int i = 0; i < m; i++) {
        int s, gs, d;
        scanf("%d%d%d", &s, &gs, &d);

        int deliver_time = g[s][gs] + g[gs][d];
        int saved_time = max(0, deliver_time - g[s][d]);

        printf("%d %d\n", deliver_time, saved_time);
    }
}

