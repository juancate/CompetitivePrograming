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

const int maxn = 100;

int n, m, N, source, sink;
int residual[maxn][maxn], stickers[maxn], parent[maxn];
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

int main() {
    int t;
    scanf("%d", &t);

    for(int case_id = 1; case_id <= t; case_id++) {
        scanf("%d%d", &n, &m);
        memset(residual, 0, sizeof residual);

        for(int i = 0; i < n; i++) {
            int k;
            scanf("%d", &k);
            memset(stickers, 0, sizeof stickers);
            for(int j = 0; j < k; j++) {
                int s;
                scanf("%d", &s);
                stickers[s-1]++;
            }

            if(i == 0) {
                for(int j = 0; j < m; j++) {
                    residual[i][j+1] = stickers[j];
                }
            }
            else {
                int p = m + i;
                for(int j = 0; j < m; j++) {
                    if(stickers[j] == 0)
                        residual[j+1][p] = 1;
                    else if(stickers[j] > 1)
                        residual[p][j+1] = stickers[j]-1;
                }
            }
        }

        source = 0;
        sink = n+m;
        N = n+m+1;

        for(int i = 1; i <= m; i++)
            residual[i][sink] = 1;

        int ans = max_flow();
        printf("Case #%d: %d\n", case_id, ans);
    }

    return 0;
}

