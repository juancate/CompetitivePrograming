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

// Algorithm: Max Flow

const int maxn = 510;
int n, m, sink, source, N, parent[maxn], residual[maxn][maxn];
bool used[maxn];
vector< pair<int,int> > g[maxn];

int get_path() {
    int where, path_capacity;

    where = sink;
    path_capacity = INF;

    while(parent[where] != -1) {
        int prev = parent[where];
        path_capacity = min(path_capacity, residual[prev][where]);
        where = prev;
    }

    if(path_capacity == INF) return 0;

    where = sink;

    while(parent[where] != -1) {
        int prev = parent[where];
        residual[prev][where] -= path_capacity;
        residual[where][prev] += path_capacity;
        where = prev;
    }

    return path_capacity;
}

int bfs() {
    queue<int> q;
    int where, next;

    memset(parent, -1, sizeof parent);
    memset(used, 0, sizeof used);

    q.push(source);
    used[source] = true;

    while(!q.empty()) {
        where = q.front();
        q.pop();

        bool sink_found = false;
        for(next = 1; next <= N; next++) {
            if(!used[next] && residual[where][next] > 0) {
                q.push(next);
                used[next] = true;
                parent[next] = where;

                if(next == sink) {
                    sink_found = true;
                    break;
                }
            }
        }
        if(sink_found) break;
    }
    return get_path();
}

long long max_flow() {
    long long mf = 0;

    while(true) {
        int flow = bfs();
        if(flow == 0) break;
        mf += flow;
    }

    return mf;
}

void dfs_min_cut(int u) {
    used[u] = true;

    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i].first;
        if(!used[v]) {
            if(residual[u][v] > 0) {
                dfs_min_cut(v);
            }
        }
    }
}

void build_residual() {
    source = 1;
    sink = 2;
    N = n;

    memset(residual, 0, sizeof residual);
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < g[i].size(); j++) {
            int v = g[i][j].first;
            residual[i][v] = g[i][j].second;
        }
    }
}

int main() {
    while(scanf("%d%d", &n, &m)) {
        if(!(n|m)) break;
        for(int i = 1; i <= n; i++)
            g[i].clear();

        for(int i = 0; i < m; i++) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            g[a].push_back(make_pair(b, c));
            g[b].push_back(make_pair(a, c));
        }
        build_residual();
        max_flow();
        memset(used, 0, sizeof used);
        dfs_min_cut(source);

        for(int i = 1; i <= n; i++) {
            if(used[i]) {
                for(int j = 0; j < g[i].size(); j++) {
                    int v = g[i][j].first;
                    if(!used[v]) {
                        printf("%d %d\n", i, v);
                    }
                }
            }
        }
        printf("\n");
    }
    return 0;
}

