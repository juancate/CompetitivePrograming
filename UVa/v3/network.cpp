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

const int MAXN = 111;

int n;
int dfs_number_counter, dfs_root, root_children;
int dfs_low[MAXN], dfs_num[MAXN], dfs_parent[MAXN];
bool articulation_vertex[MAXN];
vector<int> G[MAXN];

char line[1111];

void find_articulation_points_bridges(int u) {
    dfs_low[u] = dfs_num[u] = dfs_number_counter++;

    for(int j = 0; j < (int)G[u].size(); j++) {
        int v = G[u][j];

        if(dfs_num[v] == -1) {
            dfs_parent[v] = u;

            if(u == dfs_root) root_children++;

            find_articulation_points_bridges(v);

            if(dfs_low[v] >= dfs_num[u]) // u is an articulation point!
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
    while(~scanf("%d\n", &n) && n){
        REP(i, 0, n) G[i].clear();

        while(gets(line) && line[0] != '0') {
            stringstream ss(line);
            int v, u; ss >> v; v--;

            while(ss >> u) {
                u--;
                G[v].push_back(u);
                G[u].push_back(v);
            }
        }

        dfs_number_counter = 0;

        memset(dfs_num, -1, sizeof(dfs_num));
        memset(dfs_low, 0, sizeof(dfs_low));

        memset(dfs_parent, 0, sizeof(dfs_parent));
        memset(articulation_vertex, false, sizeof(articulation_vertex));

        for(int i = 0; i < n; i++) {
            if(dfs_num[i] < 0) {
                dfs_root = i;
                root_children = 0;
                find_articulation_points_bridges(i);
                // Special case
                articulation_vertex[dfs_root] = (root_children > 1);
            }
        }

        int critical = 0;//count(articulation_vertex, articulation_vertex + n, true);

        for(int i = 0; i < n; i++) {
            if(articulation_vertex[i])
                critical++;
            else if(G[i].size() == 0)
                critical++;
        }

        printf("%d\n", critical);
    }
}

