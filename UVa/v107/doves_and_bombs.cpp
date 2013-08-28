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
#define FOREACH(it,v) for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

// Algorithm: Articulation points

const int maxn = 10010;

int n, m, dfsNumberCounter;
int dfs_num[maxn], dfs_low[maxn], dfs_parent[maxn], pv[maxn];
vector<int> G[maxn];
vector< pair<int, int> > ans;

void dfs(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;

    bool articulation = false;
    pv[u] = 0;

    for(int j = 0; j < G[u].size(); j++) {
        int v = G[u][j];
        if(dfs_num[v] < 0) {
            dfs_parent[v] = u;

            dfs(v);

            if(dfs_low[v] >= dfs_num[u]) {
                articulation = true;
                pv[u]++;
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if(v != dfs_parent[u]) {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }

    if(dfs_parent[u] < 0 && pv[u] <= 1) articulation = false;

    if(articulation) {
        if(dfs_parent[u] >= 0) pv[u]++;
    }
    else {
        pv[u] = 1;
    }
}

void run_dfs() {
    dfsNumberCounter = 0;
    memset(dfs_num, -1, n * sizeof(int));
    memset(dfs_low, 0, n * sizeof(int));
    memset(dfs_parent, -1, n * sizeof(int));

    dfs(0);
}

bool cmp(const pair<int,int>& a, const pair<int,int>& b) {
    if(a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

void print() {
    ans.clear();

    for(int i = 0; i < n; i++) {
        ans.push_back(make_pair(i, pv[i]));
    }
    sort(ans.begin(), ans.end(), cmp);

    for(int i = 0; i < m; i++) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
    puts("");
}

int main() {
    while(scanf("%d%d", &n, &m)) {
        if(!(n|m)) break;

        memset(G, 0, sizeof G);

        while(true) {
            int a, b;
            scanf("%d%d", &a, &b);
            if(a < 0 && b < 0) break;
            G[a].push_back(b);
            G[b].push_back(a);
        }

        run_dfs();
        print();
    }
    return 0;
}
