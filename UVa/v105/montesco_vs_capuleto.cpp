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
int color[211];
vector<int> G[211];

bool dfs(int v, int c, int& w, int& b) {
    if(color[v] == 1-c) return false;
    if(color[v] == c) return true;

    color[v] = c;
    if(c == 0) b++; else w++;

    bool coloreable = true;

    REP(u, 0, G[v].size()) {
        coloreable &= dfs(G[v][u], 1-c, w, b);
    }
    return coloreable;
}

int main() {
    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);

        for(int i = 0; i < n; i++)
            G[i].clear();

        REP(i, 0, n) {
            int m; scanf("%d", &m);

            REP(j, 0, m) {
                int x; scanf("%d", &x); x--;
                if(x < n) {
                    G[i].push_back(x);
                    G[x].push_back(i);
                }
            }
        }

        memset(color, -1, sizeof(color));

        int ans = 0;

        REP(i, 0, n) {
            if(color[i] < 0) {
                int w = 0, b = 0;
                if(dfs(i, 0, w, b)) {
                    ans += max(w, b);
                }
            }
        }

        printf("%d\n", ans);
    }
}

