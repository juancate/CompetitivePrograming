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

// Problem: 10199 - Tourist Guide
// Algorithm: Articulation points

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

int n;
vector<int> G[101];
char name_a[50], name_b[50];

int dfs_number_counter, root_children, dfs_root;
int dfs_num[101], dfs_low[101], dfs_parent[101];
bool articulation_vertex[101];

void find_articulation_points_bridges(int u) {
    dfs_low[u] = dfs_num[u] = dfs_number_counter++;

    for(int j = 0; j < G[u].size(); j++) {
        int v = G[u][j];

        if(dfs_num[v] < 0) {
            dfs_parent[v] = u;

            if(u == dfs_root) root_children++;

            find_articulation_points_bridges(v);

            if(dfs_low[v] >= dfs_num[u]) // u is an articulation point
                articulation_vertex[u] = true;
            //if(dfs_low[v] > dfs_num[u]) // (u, v) is a bridge
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if(v != dfs_parent[u]) {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

int main() {
    int case_id = 0;

    while(~scanf("%d", &n) && n) {
        map<string, int> map_names;
        vector<string> names(n);

        REP(i, 0, n) {
            scanf("%s", name_a);
            map_names[name_a] = i;
            names[i] = name_a;
            G[i].clear();
        }

        int m; scanf("%d", &m);
        REP(i, 0, m) {
            scanf("%s%s", name_a, name_b);
            int u = map_names[name_a], v = map_names[name_b];

            G[u].push_back(v);
            G[v].push_back(u);
        }

        dfs_number_counter = 0;
        memset(dfs_num, -1, sizeof(dfs_num));
        memset(dfs_low, 0, sizeof(dfs_low));

        memset(dfs_parent, 0, sizeof(dfs_parent));
        memset(articulation_vertex, false, sizeof(articulation_vertex));

        for(int i = 0; i < n; i++) {
            if(dfs_num[i] < 0) {
                dfs_root = i, root_children = 0;

                find_articulation_points_bridges(i);

                articulation_vertex[i] = (root_children > 1);
            }
        }

        int ans = 0;
        vector<string> cities;

        for(int i = 0; i < n; i++) {
            if(articulation_vertex[i]) {
                ans++;
                cities.push_back(names[i]);
            }
        }

        sort(ALL(cities));

        if(case_id) puts("");

        printf("City map #%d: %d camera(s) found\n", ++case_id, ans);
        for(int i = 0; i < cities.size(); i++)
            puts(cities[i].c_str());
    }
}

