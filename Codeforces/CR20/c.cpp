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
#include <set>
#include <map>
#include <algorithm>

#define D(x) cerr << #x << " = " << x << endl
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

using namespace std;

typedef pair<int, int> ii;
#define mp make_pair

int n, m;
vector< vector<ii> > G;

void dijkstra(int start, int end) {
    vector<int64> dist(n, INFLL);
    vector<int> parent(n, -1);
    vector<bool> visited(n, false);

    priority_queue<ii> Q;

    Q.push( mp(0, start) );
    dist[start] = 0;
    visited[start] = 0;

    while(!Q.empty()) {
        int v = Q.top().second;
        int cost = -Q.top().first;
        Q.pop();

        if(v == end) {
            int prev = v;
            vector<int> ans;
            while(v != -1) {
                prev = v;
                ans.push_back(v+1);
                v = parent[v];
            }
            for(int i = ans.size() - 1; i >= 0; i--) {
                if(i < ans.size() - 1) cout << ' ';
                cout << ans[i];
            }
            cout << endl;
            return;
        }

        if(visited[v]) continue;

        visited[v] = true;

        for(int i = 0; i < (int)G[v].size(); i++) {
            int u = G[v][i].first;
            int d = G[v][i].second;

            if(dist[v] + d < dist[u]) {
                dist[u] = dist[v] + d;
                parent[u] = v;
                Q.push( mp(-dist[u], u) );
            }
        }
    }
    cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;

    G.resize(n);

    REP(i, 0, m) {
        int a, b, w;
        cin >> a >> b >> w;
        a--, b--;
        G[a].push_back( mp(b, w) );
        G[b].push_back( mp(a, w) );
    }
    dijkstra(0, n-1);
}

