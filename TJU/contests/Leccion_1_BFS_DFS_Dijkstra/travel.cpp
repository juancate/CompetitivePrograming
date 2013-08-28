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

#define mp make_pair

const int maxn = 1010;

int n, m;
vector< pair<int, int> > G[maxn];
bool visited[maxn];
int d[maxn];

int dijkstra(int start, int end) {
    memset(d, 0x3f, sizeof(d));
    memset(visited, false, sizeof(visited));

    priority_queue< pair<int, int> > Q;
    Q.push( mp(0, start) );
    d[start] = 0;

    while(!Q.empty()) {
        int u = Q.top().second;
        int cost = -Q.top().first;
        Q.pop();

        if(visited[u]) continue;
        visited[u] = true;

        if(u == end) return cost;

        REP(j, 0, G[u].size()) {
            int v = G[u][j].first;
            int new_cost = cost + G[u][j].second;

            if(new_cost < d[v]) {
                d[v] = new_cost;
                Q.push( mp(-new_cost, v) );
            }
        }
    }

    return -1;
}

int main() {
    int t; scanf("%d", &t);

    while(t--) {
        scanf("%d%d", &n, &m);

        int s, t; scanf("%d%d", &s, &t);
        s--, t--;

        REP(i, 0, m) {
            int a, b, c; scanf("%d%d%d", &a, &b, &c);
            a--, b--;

            G[a].push_back( mp(b, c) );
            G[b].push_back( mp(a, c) );
        }

        printf("%d\n", dijkstra(s, t));

        if(t)
            REP(i, 0, n) G[i].clear();
    }
}

