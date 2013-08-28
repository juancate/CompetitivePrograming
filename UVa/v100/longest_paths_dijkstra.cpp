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

typedef pair<int,int> ii;

const int MAXN = 111;

int n;
int in_degree[MAXN], d[MAXN];
vector<int> G[MAXN];
bool visited[MAXN];

void dijkstra(int start, int case_id) {
    memset(d, 0x3f, sizeof(d));
    memset(visited, false, sizeof(visited));

    priority_queue< ii, vector<ii>, greater<ii> > Q;

    d[start] = 0;
    Q.push( ii(0, start) );

    while(!Q.empty()) {
        int v = Q.top().second;
        int cost = Q.top().first;
        Q.pop();

        if(visited[v]) continue;
        visited[v] = true;

        FOREACH(u, G[v]) {
            int new_cost = cost - 1;
            if(new_cost < d[*u]) {
                d[*u] = new_cost;
                Q.push( ii(new_cost, *u) );
            }
        }
    }

    int max_id = -1;

    REP(i, 0, n) {
        d[i] = -d[i];
    }

    REP(i, 0, n) {
        if(-d[i] == 0x3f3f3f3f) continue;
        if(max_id == -1 || d[max_id] < d[i])
            max_id = i;
    }

    start++, max_id++;
    printf("Case %d: The longest path from %d has length %d, finishing at %d.\n", case_id, start, d[max_id-1], max_id);

}

int main() {
    int case_id = 0;
    while(~scanf("%d", &n) && n) {
        REP(i, 0, n) G[i].clear();

        int start; scanf("%d", &start); start--;

        int p, q;
        while(~scanf("%d%d", &p, &q) && (p|q)) {
            p--, q--;
            G[p].push_back(q);
        }

        dijkstra(start, ++case_id);
        puts("");
    }
}

