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

const int maxn = 101;

int n;
bool g[maxn][maxn], visited[maxn], sol[maxn][maxn];

void bfs(int ignore) {
    memset(visited, false, sizeof(visited));

    queue<int> Q;
    Q.push(0);

    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();

        if(visited[u]) continue;
        visited[u] = true;

        for(int v = 0; v < n; v++) {
            if(v == ignore)
                continue;
            if(g[u][v]) {
                Q.push(v);
            }
        }
    }
}

void println() {
    printf("+");
    for(int i = 0; i < n+n-1; i++)
        printf("-");
    printf("+\n");
}

int main() {
    int t; scanf("%d", &t);

    for(int case_id = 1; case_id <= t; case_id++) {
        scanf("%d", &n);

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                scanf("%d", &g[i][j]);

        memset(sol, false, sizeof(sol));

        bfs(0);

        for(int i = 0; i < n; i++) {
            if(visited[i]) {
                sol[0][i] = true;
                sol[i][i] = true;
            }
        }

        for(int u = 1; u < n; u++) {
            bfs(u);
            for(int i = 0; i < n; i++) {
                if(!visited[i] && sol[0][i]) {
                    sol[u][i] = true;
                }
            }
        }

        printf("Case %d:\n", case_id);
        println();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                printf("|%c", sol[i][j]? 'Y' : 'N');
            }
            puts("|");
            println();
        }
    }
}

