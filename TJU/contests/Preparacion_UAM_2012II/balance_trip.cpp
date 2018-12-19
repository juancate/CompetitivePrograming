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
const double EPS = 1e-13;

#define mp make_pair

const int maxn = 210;
const int maxm = 1010;

struct edge {
    int from, to, cost;
    edge(int f = 0, int t = 0, int c = 0) {
        from = f, to = t, cost = c;
    }

    bool operator<(const edge& a) const {
        return cost < a.cost;
    }
};

edge g[maxm];
int n, m;

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
    while(scanf("%d%d", &n, &m) && (n|m)) {
        REP(i, 0, m) {
            int u, v, d; scanf("%d%d%d", &u, &v, &d);
            u--, v--;

            g[i] = edge(u, v, d);
        }

        sort(g, g+m);

        int s, t; scanf("%d%d", &s, &t);
        s--, t--;

        int best = INF;

        for(int i = 0; i < m; i++) {
            init();

            int j = i;
            while(j < m && find(s) != find(t)) {
                unite(g[j].from, g[j].to);
                j++;
            }
            j--;

            if(find(s) == find(t)) {
                best = min(best, g[j].cost - g[i].cost);
            }
        }

        if(best == INF) best = -1;

        printf("%d\n", best);
    }
}

