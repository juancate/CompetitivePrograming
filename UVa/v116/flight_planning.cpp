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
#define foreach(it,v) for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

int n;
set<int> G[2501];
int d[2501];
bool visited[2501];

int dfs(int u) {
    if(visited[u]) return -INF;
    if(d[u]) return d[u];

    int ans = 0;
    visited[u] = true;

    foreach(v, G[u]) {
        ans = max(ans, 1 + dfs(*v));
    }

    return d[u] = ans;
}

// opt with memo
int find_center(int u, int p, int t) {
    if(d[u] == d[p/2]) return u;
    foreach(v, G[u]) {
        if(*v == t) continue;
        return find_center(*v, p, u);
    }
    return p;
}


int diameter_sibiling(int u, int v, bool r = false) {
    int ans = 0;
    foreach(t, G[u]) {
        if(*t == v) continue;
        ans = max(ans, d[*t]);
    }
    if(r && ans) ans++;
    return ans;
}

int diameter_rooting(int u, int v) {
    return max(d[v], 1 + diameter_sibiling(u, v));
}

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        scanf("%d", &n);

        for(int i = 0; i < n; i++)
            G[i].clear();

        for(int i = 1; i < n; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            a--, b--;
            G[a].insert(b);
            G[b].insert(a);
        }

        int best = INF;
        // calculate diameter
        memset(d, 0, n*sizeof(int));
        memset(visited, false, sizeof visited);
        dfs(0);

        // remove edges
        int rr = -1, lr = -1, ra = -1, la = -1;
        for(int u = 0; u < n; u++) {
            foreach(it, G[u]) {
                int v = *it;

                // recalc diameter
                int oldu = d[u], oldv = d[v];
                d[u] = d[v] = 0;
                d[u] = diameter_sibiling(u, v, true);
                d[v] = diameter_sibiling(v, u, true);

                int cu = find_center(u, u, v);
                int cv = find_center(v, v, u);

                int dru = diameter_rooting(u, cu);
                int drv = diameter_rooting(v, cv);
                fprintf(stderr, "u = %d v = %d du = %d dv = %d cu = %d cv = %d dru = %d drv = %d\n",
                        u, v, d[u], d[v], cu, cv, dru, drv);
                int nd = max(dru, drv) + 1;
                d[u] = oldu;
                d[v] = oldv;

                if(best > nd) {
                    best = nd;
                    rr = u+1, lr = v+1;
                    ra = cu+1, la = cv+1;
                }
                //D(best);

                //G[u].insert(*it);
                //G[v].insert(u);
            }
        }

        printf("%d\n%d %d\n%d %d\n",
               best, rr, lr, ra, la);
    }

    return 0;
}
