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

int n, m;
int color[111];
vector< vector<int> > g;

bool dfs(int i, int c) {
    if(color[i] == 1-c) return false;
    if(color[i] == c) return true;

    color[i] = c;

    bool colorable = true;
    REP(j, 0, g[i].size()) {
        colorable &= dfs(g[i][j], 1-c);
    }
    return colorable;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;

    g.resize(n);

    REP(i, 0, m) {
        int u, v; cin >> u >> v; u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int bench = 0;

    memset(color, -1, sizeof(color));

    REP(i, 0, n) {
        if(color[i] < 0) {
            if(!dfs(i, 0))
                bench++;
        }
    }

    if((n - bench) & 1) bench++;
    cout << bench << endl;
}

