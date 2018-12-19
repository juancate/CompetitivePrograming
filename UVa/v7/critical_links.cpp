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

int n;
vector< vector<int> > G;

int dfs_number_counter, dfs_root, root_children;
vector<int> dfs_num, dfs_low, dfs_parent;
vector< vector<bool> > bridges;

void find_articulation_points_bridges(int u) {
    dfs_low[u] = dfs_num[u] = dfs_number_counter++;

    for(int j = 0; j < G[u].size(); j++) {
        int v = G[u][j];

        if(dfs_num[v] < 0) {
            dfs_parent[v] = u;

            if(u == dfs_root) root_children++;

            find_articulation_points_bridges(v);

            //if(dfs_low[v] >= dfs_num[u]) // u is an articulation point
            //    articulation_vertex[u] = true;
            if(dfs_low[v] > dfs_num[u]) // find bridges
                bridges[u][v] = bridges[v][u] = true;

            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if(v != dfs_parent[u]) {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

int main() {
    while(~scanf("%d", &n)) {
        G.assign(n, vector<int>());

        REP(i, 0, n) {
            int v, e, u;
            scanf("%d (%d)", &v, &e);
            REP(j, 0, e) {
                scanf("%d", &u);
                G[v].push_back(u);
            }
        }

        dfs_number_counter = 0;

        dfs_num.assign(n, -1); dfs_low.assign(n, 0); dfs_parent.assign(n, 0);
        bridges.assign(n, vector<bool>(n, false));

        for(int i = 0; i < n; i++) {
            if(dfs_num[i] < 0) {
                dfs_root = i, root_children = 0;

                find_articulation_points_bridges(i);
            }
        }

        vector< pair<int, int> > bridges_points;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(bridges[i][j]) {
                    ans++;
                    bridges_points.push_back( make_pair(i, j) );
                }
            }
        }

        printf("%d critical links\n", ans);
        REP(i, 0, ans) {
            printf("%d - %d\n", bridges_points[i].first, bridges_points[i].second);
        }
        puts("");
    }
}

