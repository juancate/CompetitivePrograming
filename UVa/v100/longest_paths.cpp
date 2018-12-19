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

int in_degree[MAXN], dp[MAXN];
vector<int> G[MAXN];

int main() {
    int n, case_id = 0;
    while(~scanf("%d", &n) && n) {
        REP(i, 0, n) G[i].clear();
        memset(in_degree, 0, sizeof(in_degree));

        int start; scanf("%d", &start); start--;

        int p, q;
        while(~scanf("%d%d", &p, &q) && (p|q)) {
            p--, q--;
            G[p].push_back(q);
            in_degree[q]++;
        }

        vector<int> topolSort;
        vector<bool> visited(n, false);
        queue<int> Q;
        Q.push(start);

        REP(i, 0, n)
            if(in_degree[i] == 0 && i != start)
                Q.push(i);

        while(!Q.empty()) {
            int v = Q.front();
            Q.pop();

            if(visited[v]) continue;
            visited[v] = true;
            topolSort.push_back(v);

            FOREACH(u, G[v]) {
                in_degree[*u]--;
                if(in_degree[*u] == 0)
                    Q.push(*u);
            }
        }

        REP(i, 0, topolSort.size())
            cerr << topolSort[i] << ' ';
        cerr << endl;

        memset(dp, 0, sizeof(dp));

        FOREACH(v, topolSort) {
            FOREACH(u, G[*v]) {
                if(dp[*u] <= dp[*v] + 1)
                    dp[*u] = dp[*v] + 1;
            }
        }

        cerr << "{";
        for(int i = 0; i < n; i++)
            cerr << dp[i] << ' ';
        cerr << "}\n";

        int max_id = -1;

        REP(i, 0, n) {
            if(i == start) continue;
            if(max_id == -1 || dp[max_id] < dp[i])
                max_id = i;
        }

        if(case_id) puts("");

        start++, max_id++;
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n", ++case_id, start, dp[max_id-1], max_id);
    }
}

