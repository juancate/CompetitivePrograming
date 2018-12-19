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

// Problem: 11857 - Driving Range
// Algorithm: MST - Kruskal

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

#define mp make_pair
#define mt(x, y, z) mp(x, mp(y, z))
#define cost first
#define from second.first
#define to second.second

const int MAXN = 1e6 + 10;

priority_queue<iii> Q;
int dsu[MAXN], rank[MAXN], size[MAXN], n, m;

void init() {
    for(int i = 0; i < n; i++) {
        dsu[i] = i;
        rank[i] = 0;
        size[i] = 1;
    }
}

int find(int x) {
    return (x == dsu[x])? x : dsu[x] = find(dsu[x]);
}

void unite(int x, int y) {
    int xp = find(x), yp = find(y);

    if(xp == yp)
        return;
    if(rank[xp] < rank[yp]) {
        dsu[xp] = yp;
        size[yp] += size[xp];
    }
    else {
        dsu[yp] = xp;
        size[xp] += size[yp];
        if(rank[xp] == rank[yp])
            rank[xp]++;
    }
}

int kruskal() {
    init();

    int edg = 0;
    int ans = -INF;

    while(edg < n-1 && !Q.empty()) {
        int c = -Q.top().cost;
        int u = Q.top().from;
        int v = Q.top().to;
        Q.pop();

        int a = find(u);
        int b = find(v);

        if(a != b) {
            ans = max(ans, c);
            unite(a, b);
            edg++;
        }
    }

    return ans;
}

int main() {
    while(~scanf("%d%d", &n, &m) && (n|m)) {
        REP(i, 0, m) {
            int u, v, c; scanf("%d%d%d", &u, &v, &c);
            Q.push( mt(-c, u, v) );
        }

        int ans = kruskal();

        REP(i, 0, n) find(i);

        if(size[dsu[0]] != n) puts("IMPOSSIBLE");
        else printf("%d\n", ans);

        while(!Q.empty()) Q.pop();
    }
}

