// 11813 - Shopping
// Algorithm: Dijkstra, DP+bitmask (TSP)
// Status: AC

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
#include <climits>

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
typedef pair<int, int> ii;
typedef vector<ii> vii;

int n, s;
vector<int> S;
vector<vii> G;
vector< vector<int> > D;

int dp[15][1<<15];

void dijkstra(int start, vector<int>& d) {
    vector<bool> visited(n, false);

    priority_queue< ii, vii, greater<ii> > Q;
    Q.push( mp(0, start) );
    d[start] = 0;

    while(!Q.empty()) {
        int cost = Q.top().first;
        int v = Q.top().second;
        Q.pop();

        if(cost > d[v]) continue;
        if(visited[v]) continue;

        visited[v] = true;

        REP(j, 0, G[v].size()) {
            ii u = G[v][j];

            int new_cost = cost + u.second;
            if(new_cost < d[u.first]) {
                d[u.first] = new_cost;
                Q.push( mp(new_cost, u.first) );
            }
        }
    }
}

int solve(int v, int mask) {
    if(mask == (1 << (s+1)) - 1)
        return D[v][0];

    if(dp[v][mask] != -1)
        return dp[v][mask];

    int ans = INT_MAX;

    REP(next, 0, s+1)
        if((mask & (1 << next)) == 0)
            ans = min(ans, D[v][S[next]] + solve(next, mask | (1 << next)));

    return dp[v][mask] = ans;
}

int main() {
    int t; scanf("%d", &t);

    while(t--) {
        int m;
        scanf("%d%d", &n, &m);

        G.assign(n, vector<ii>());

        REP(i, 0, m) {
            int x, y, d; scanf("%d%d%d", &x, &y, &d);
            G[x].push_back( mp(y, d) );
            G[y].push_back( mp(x, d) );
        }

        scanf("%d", &s);

        D.assign(s+1, vector<int>( n, INT_MAX ));
        S.assign(s+1, -1);

        S[0] = 0;
        dijkstra(0, D[0]);

        REP(i, 0, s) {
            int x; scanf("%d", &x);
            S[i+1] = x;
            // calc dijkstra to S[i+1]
            dijkstra(x, D[i+1]);
        }

        memset(dp, -1, sizeof(dp));

        // make dp+bitmask (TSP)
        int ans = solve(0, 1);
        printf("%d\n", ans);
    }
}

