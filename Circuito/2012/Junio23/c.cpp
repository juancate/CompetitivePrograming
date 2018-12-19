#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

const int MAXV = 5000 + 10;
const int MAXE = 150000 + 10;

#define mp(x,y) make_pair(x, y)
#define to second
#define cost first

typedef pair<int, int> ii;
typedef vector< ii > vii;

int J, B, C, N, S;
vii g[MAXV];

void dijkstra(int start, vector<int>& d) {
    int dist[J+1];
    bool visited[J+1];
    priority_queue<ii> Q;

    memset(dist, 0x3f, sizeof(dist));
    memset(visited, false, sizeof(visited));

    dist[start] = 0;
    Q.push( mp(0, start) );

    while(!Q.empty()) {
        int u = Q.top().to;
        int c = -Q.top().cost;
        Q.pop();

        if(visited[u]) continue;
        visited[u] = true;

        REP(i, 0, g[u].size()) {
            int v = g[u][i].to;
            int cv = g[u][i].cost + c;
            if(cv < dist[v]) {
                dist[v] = cv;
                Q.push( mp(-cv, v) );
            }
        }
    }

    REP(i, 0, J) d[i] = dist[i];
}

int main() {
    while(scanf("%d%d%d%d%d", &J, &B, &C, &N, &S) && J != -1) {
        REP(i,0,J+1) g[i].clear();
        B--, C--, N--;

        REP(i, 0, S) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            a--, b--;
            g[a].push_back(mp(c, b));
            g[b].push_back(mp(c, a));
        }

        vector<int> bar(J), charly(J), nito(J);

        dijkstra(B, bar); dijkstra(C, charly); dijkstra(N, nito);

        int ans = B;

        REP(i, 0, J) {
            if(bar[i] + charly[i] == bar[C] && bar[i] + nito[i] == bar[N]) {
                if(bar[i] > bar[ans]) {
                    ans = i;
                }
            }
        }

        printf("%d %d %d\n", bar[ans], charly[ans], nito[ans]);
    }
}

