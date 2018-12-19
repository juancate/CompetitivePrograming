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

int n;
vector<int> G[310];
int color[310];

bool dfs(int u, int c) {
    if(color[u] == c) return true;
    if(color[u] != -1 && color[u] != c)
        return false;

    color[u] = c;

    for(int i = 0; i < G[i].size(); i++) {
        int v = G[u][i];
        if(!dfs(v, 1-c))
            return false;
    }
    return true;
}

int main() {
    while(scanf("%d", &n)) {
        if(!n) break;

        memset(G, 0, sizeof G);
        memset(color, -1, sizeof color);

        int a, b;
        while(true) {
            scanf("%d%d", &a, &b);
            if(!(a|b)) break;
            a--; b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }

        puts(dfs(0, 0)? "YES" : "NO");
    }
    return 0;
}

