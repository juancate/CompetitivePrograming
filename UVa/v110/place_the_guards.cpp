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

int V, E;
vector<int> G[211];
int color[211];

bool dfs(int v, int c, int& cnt, int& black) {
    if(color[v] == 1-c) return false;
    if(color[v] == c) return true;

    color[v] = c;
    cnt++;
    if(c == 0) black++;

    bool colorable = true;

    REP(u, 0, G[v].size()) {
        colorable &= dfs(G[v][u], 1-c, cnt, black);
    }

    return colorable;
}

int main() {
    int t; scanf("%d", &t);

    while(t--) {
        scanf("%d%d", &V, &E);

        REP(i, 0, V) G[i].clear();

        REP(i, 0, E) {
            int a, b; scanf("%d%d", &a, &b);
            G[a].push_back(b);
            G[b].push_back(a);
        }

        memset(color, -1, sizeof(color));
        bool ok = true;
        int ans = 0;

        for(int i = 0; i < V && ok; i++) {
            if(color[i] < 0) {
                int cnt = 0, black = 0;
                if(dfs(i, 0, cnt, black)) {
                    if(cnt == 1) {
                        ans += cnt;
                    } else {
                        ans += min(black, cnt - black);
                    }
                }
                else
                    ok = false;
            }
        }
        printf("%d\n", (ok)? ans : -1);
    }
}

