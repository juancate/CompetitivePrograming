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

const int maxn = 2*111;
int n, m, residual[maxn][maxn], C[111], source, sink;
int parent[maxn], N;
bool used[maxn];
vector< pair<int,int> > g[111];

int bfs() {
    queue<int> q;
    int where, next, path_capacity;

    memset(parent, -1, sizeof parent);
    memset(used, 0, sizeof used);

    q.push(source);
    used[source] = true;

    while(!q.empty()) {
        where = q.front();
        q.pop();

        bool sink_found = false;
        for(next = 0; next <= N; next++) {
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

int max_flow() {
    int ret = 0;

    while(true) {
        int flow = bfs();
        if(flow == 0)
            break;
        ret += flow;
    }

    return ret;
}

void build_residual() {
    N = 2*n+1;

    for(int i = 1; i <= n; i++)
        residual[i][i+n] = C[i];

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < g[i].size(); j++) {
            int v = g[i][j].first;
            residual[i+n][v] = g[i][j].second;
        }
    }

    int b, d;
    scanf("%d%d", &b, &d);
    for(int i = 0; i < b; i++) {
        int a;
        scanf("%d", &a);
        residual[source][a] = INF;
    }

    for(int i = 0; i < d; i++) {
        int a;
        scanf("%d", &a);
        residual[a+n][sink] = INF;
    }
}

int main() {
    while(scanf("%d", &n) != EOF) {
        for(int i = 1; i <= n; i++) {
            scanf("%d", &C[i]);
            g[i].clear();
        }

        memset(residual, 0, sizeof residual);

        scanf("%d", &m);
        for(int i = 0; i < m; i++) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            g[a].push_back(make_pair(b, c));
        }

        source = 0;
        sink = 2*n + 1;
        build_residual();
        int ans = max_flow();
        printf("%d\n", ans);
    }
    return 0;
}

