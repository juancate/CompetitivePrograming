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

const int maxn = 1100;

int source, sink, N, nk, np;
int parent[maxn], cat_size[maxn], residual[maxn][maxn];
vector<int> g[21];
bool used[maxn];

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
        for(next = 0; next < N; next++) {
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

int max_flow() {
    int mf = 0;
    while(true) {
        int flow = bfs();
        if(flow == 0) break;
        mf += flow;
    }

    return mf;
}

void build_residual() {
    N = np+nk+2;
    source = N-1;
    sink = 0;

    for(int i = np+1, j = 0; i <= np+nk; i++, j++)
        residual[source][i] = cat_size[j];
    for(int i = 1; i <= np; i++)
        residual[i][sink] = 1;
}

int main() {
    while(scanf("%d%d", &nk, &np)) {
        if(!(nk|np)) break;

        for(int i = 0; i <= nk; i++)
            g[i].clear();

        int sum = 0;
        for(int i = 0; i < nk; i++) {
            scanf("%d", &cat_size[i]);
            sum += cat_size[i];
        }

        memset(residual, 0, sizeof residual);

        for(int i = 1; i <= np; i++) {
            int k, c;
            scanf("%d", &k);
            for(int j = 0; j < k; j++) {
                scanf("%d", &c);
                residual[np+c][i] = 1;
                g[c].push_back(i);
            }
        }

        build_residual();
        int mf = max_flow();

        if(mf != sum) {
            puts("0");
        }
        else {
            puts("1");
            for(int i = 1; i <= nk; i++) {
                bool first = true;
                for(int j = 0; j < g[i].size(); j++) {
                    int v = g[i][j];
                    if(residual[i+np][v] == 0) {
                        if(!first) printf(" ");
                        printf("%d", v);
                        first = false;
                    }
                }
                printf("\n");
            }
        }
    }

    return 0;
}

