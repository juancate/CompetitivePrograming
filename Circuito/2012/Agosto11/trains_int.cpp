#include <iostream>
#include <sstream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <cassert>

#define D(x) cerr << #x " = " << x << endl

using namespace std;

const double EPS = 1e-13;

int compareTo(double x, double y, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

typedef long long int64;
const int INF = 1e9;
const int64 INFLL = 1e18;

const int MAXN = 111;

int n;
int64 GA[MAXN][MAXN], GB[MAXN][MAXN];
int64 d[MAXN];
bool visited[MAXN];

#define mp make_pair

int64 dijkstra(int source, int sink, int64 a) {
    for(int i = 0; i < n; i++) {
        d[i] = 1LL<<62;
        visited[i] = false;
    }

    d[source] = 0;
    priority_queue< pair<int64, int>, vector< pair<int64, int> >, greater< pair<int64, int> > > Q;
    Q.push( mp(0, source) );
    //visited[source] = true;

    while(!Q.empty()) {
        int v = Q.top().second;
        int64 cost = Q.top().first;

        assert(cost >= 0);
        Q.pop();

        if(cost > d[v]) continue;
        if(v == sink) return cost;
        //if(visited[v]) continue;
        //visited[v] = true;

        for(int u = 0; u < n; u++) {
            if(GA[v][u] == -1 && GB[v][u] == -1) continue;
            int64 diff;
            if(GA[v][u] != -1 && GB[v][u] != -1) {
                diff = a * GA[v][u] + (10000LL - a) * GB[v][u];
            } else {
                diff = max(GA[u][v], GB[v][u]);
            }
            if(diff + cost < d[u]) {
                d[u] = diff + cost;
                Q.push(mp(diff + cost, u));
            }
        }
    }
    assert(false);
    return -1;
}

int main() {
    int ma, mb, k;
    while(~scanf("%d%d%d%d", &n, &ma, &mb, &k)) {
    	if(n == -1 && ma == -1 && mb == -1 && k == -1)
    	    break;

    	memset(GA, -1, sizeof(GA));
    	memset(GB, -1, sizeof(GB));

    	for(int i = 0; i < ma; i++) {
    	    int a, b, c;
    	    scanf("%d%d%d", &a, &b, &c);
    	    GA[a][b] = GA[b][a] = c * 10000LL;
    	}
    	for(int i = 0; i < mb; i++) {
    	    int a, b, c;
    	    scanf("%d%d%d", &a, &b, &c);
            GB[a][b] = GB[b][a] = c * 10000LL;
    	}
    	for(int i = 0; i < k; i++) {
    	    double x;
    	    scanf("%lf", &x);
            stringstream ss;
            ss << x;
            assert(ss.str().size() <= 6);

            int64 a = int64(x * 10000LL);

            double ans = dijkstra(0, n-1, a) / 10000. / 10000.;
            ans = floor(ans);
    	    printf("%.0f\n", ans);
    	}
    }
}
