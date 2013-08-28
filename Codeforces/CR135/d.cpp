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

#define mp make_pair

const int MAXN = 2e5 + 5;

int n, best;
vector< pair<int, int> > G[MAXN];
vector<int> f, g;

void dfs(int v, int parent) {
    f[v] = 0;
    for(int i = 0; i < G[v].size(); i++) {
        int u = G[v][i].first, cost = G[v][i].second;

        if(u == parent) continue;

        dfs(u, v);

        f[v] += f[u] + cost;
    }
}

void dfs2(int v, int parent) {
    for(int i = 0; i < G[v].size(); i++) {
        int u = G[v][i].first, cost = G[v][i].second;

        if(u == parent) continue;

        g[u] = g[v] - cost + (1 - cost);

        dfs2(u, v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;

    f.assign(n, 0);
    g.assign(n, 0);

    REP(i, 0, n-1) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back( mp(v, 0) );
        G[v].push_back( mp(u, 1) );
    }

    dfs(0, -1);

    g[0] = f[0];

    dfs2(0, -1);

    best = *min_element(ALL(g));

    cout << best << endl;
    REP(i, 0, n)
        if(g[i] == best)
            cout << (i+1) << ' ';
    cout << endl;
}

