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

const int maxn = 10010;

int n, m;
int pset[maxn], rank[maxn];
vector< vector<int> > G;

int dfsCounter, dfsRoot, rootChildren;
vector<int> dfs_num, dfs_low, dfs_parent;

void init(int n) {
    for(int i = 0; i < n; i++) {
        pset[i] = i;
        rank[i] = 0;
    }
}

int find(int x) {
    return (pset[x] == x)? x : pset[x] = find(pset[x]);
}

void unite(int x, int y) {
    int px = find(x);
    int py = find(y);

    if(px == py) return;

    if(rank[px] < rank[py]) {
        pset[px] = py;
    }
    else {
        pset[py] = px;
        if(rank[py] == rank[px])
            rank[px]++;
    }
}

void articulationPointsAndBridges(int u) {
    dfs_low[u] = dfs_num[u] = dfsCounter++;
    for(int j = 0; j < (int)G[u].size(); j++) {
        int v = G[u][j];

        if(dfs_num[v] < 0) {
            dfs_parent[v] = u;
            if(u == dfsRoot) rootChildren++;

            articulationPointsAndBridges(v);

            //if(dfs_low[v] >= dfs_num[u]) Articulation Point
            if(dfs_low[v] > dfs_num[u]) {// Bridge
                unite(u, v);
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if(v != dfs_parent[u])
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

bool simple_path(int u, int v) {
    return (find(u) == find(v));
}

int main() {
    int q;
    while(scanf("%d%d%d", &n, &m, &q)) {
        if((n|m|q) == 0) break;

        G.clear(); G.resize(n);

        REP(i, 0, m) {
            int a, b; scanf("%d%d", &a, &b);
            a--, b--;

            G[a].push_back(b);
            G[b].push_back(a);
        }

        dfsCounter = 0; dfs_num.assign(n, -1); dfs_low.assign(n, 0);
        dfs_parent.assign(n, 0);
        init(n);

        for(int i = 0; i < n; i++) {
            if(dfs_num[i] < 0) {
                dfsRoot = i; rootChildren = 0;
                articulationPointsAndBridges(i);
            }
        }

        while(q--) {
            int s, t;
            scanf("%d%d", &s, &t); s--, t--;
            if(simple_path(s, t))
                puts("Y");
            else
                puts("N");
        }
        puts("-");
    }
}

