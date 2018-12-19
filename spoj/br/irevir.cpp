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

#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

const int MAXN = 2000 + 10;

int n, m;
vector<int> G[MAXN][2];
bool visited[MAXN];

bool dfs(int v, int k) {
    if(visited[v]) return false;
    visited[v] = true;

    for(int i = 0; i < (int)G[v][k].size(); i++) {
        dfs(G[v][k][i], k);
    }

    return true;
}

int main() {
    while(~scanf("%d%d", &n, &m) && n) {
        for(int i = 0; i < n; i++) {
            G[i][0].clear();
            G[i][1].clear();
        }

        for(int i = 0; i < m; i++) {
            int v, w, p;
            scanf("%d%d%d", &v, &w, &p);
            v--, w--;

            G[v][0].push_back(w);
            G[w][1].push_back(v);

            if(p == 2) {
                G[w][0].push_back(v);
                G[v][1].push_back(w);
            }
        }

        memset(visited, false, sizeof(visited));

        int components1 = 0;

        for(int i = 0; i < n; i++) {
            if(!visited[i] && dfs(i, 0)) {
                components1++;
            }
        }

        memset(visited, false, sizeof(visited));

        int components2 = 0;

        for(int i = 0; i < n; i++) {
            if(!visited[i] && dfs(i, 1)) {
                components2++;
            }
        }

        if(components1 == 1 && components2 == 1) puts("1");
        else puts("0");
    }
}

