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

#define mp make_pair

const int maxn = 100010;

int n, cost[maxn];
int64 sum, ans;
bool visited[maxn];
vector< vector< pair<int, int> > > G;

void dfs(int u, int64 sum) {
    if(visited[u]) return;

    visited[u] = true;

    for(int i = 0; i < G[u].size(); i++) {
        pair<int, int> v = G[u][i];

        if(visited[v.first]) continue;

        int64 temp = sum - v.second;
        ans = min(ans, temp + cost[v.first]);

        dfs(v.first, temp);
    }
}

int main() {
    int t; scanf("%d", &t);

    while(t--) {
        scanf("%d", &n);

        for(int i = 0; i <= n; i++)
            scanf("%d", &cost[i]);

        G.clear();
        G.resize(n+1);
        sum = 0;

        for(int i = 0; i < n; i++) {
            int a, b, c; scanf("%d%d%d", &a, &b, &c);
            G[a].push_back( mp(b, c) );
            G[b].push_back( mp(a, c) );
            sum += c;
        }

        sum = 2 * sum;
        ans = sum + cost[0];

        memset(visited, false, sizeof(visited));

        dfs(0, sum);

        printf("%lld\n", ans);
    }
}

