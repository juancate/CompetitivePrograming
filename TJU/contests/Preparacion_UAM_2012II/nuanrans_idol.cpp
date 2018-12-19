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

const int maxn = 100010;

int n;
int dsu[maxn], rank[maxn];

void init() {
    for(int i = 0; i < n; i++) {
        dsu[i] = i; rank[i] = 0;
    }
}

int find(int x) {
    return (x == dsu[x])? x : dsu[x] = find(dsu[x]);
}

void unite(int x, int y) {
    int rx = find(x), ry = find(y);

    if(rx == ry)
        return;

    if(rank[rx] < rank[ry]) {
        dsu[rx] = ry;
    } else {
        dsu[ry] = rx;
        if(rank[rx] == rank[ry])
            rank[rx]++;
    }
}

int main() {
    int m, k;
    while(~scanf("%d%d%d", &n, &m, &k)) {
        init();

        REP(i, 0, m) {
            int x, y; scanf("%d%d", &x, &y);
            x--, y--;

            unite(x, y);
        }

        REP(i, 0, k) {
            int x; scanf("%d", &x); x--;

            if(find(x) == find(0))
                puts("Yes");
            else
                puts("No");
        }
    }
}

