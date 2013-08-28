#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <cmath>

using namespace std;

typedef long long int64;

const int MAXN = 111;

int n;
int GA[MAXN][MAXN], GB[MAXN][MAXN];
double d[MAXN];
bool visited[MAXN];

#define mp make_pair

int64 dijkstra(int source, int sink, double a) {
    for(int i = 0; i < n; i++) {
        d[i] = 1e50;
        visited[i] = false;
    }

    d[source] = 0;
    priority_queue< pair<double, int>, vector< pair<double, int> >, greater< pair<double, int> > > Q;
    Q.push( mp(0.0, source) );
    //visited[source] = true;

    while(!Q.empty()) {
        int v = Q.top().second;
        double cost = Q.top().first;
        Q.pop();

        if(cost > d[v]) continue;
        if(v == sink) return floor(cost);
        //if(visited[v]) continue;
        //visited[v] = true;

        for(int u = 0; u < n; u++) {
            if(GA[v][u] == -1 && GB[v][u] == -1) continue;
            double diff;
            if(GA[v][u] != -1 && GB[v][u] != -1) {
                diff = a * GA[v][u] + (1. - a) * GB[v][u];
            } else {
                diff = max(GA[u][v], GB[v][u]);
            }
            if(diff + cost < d[u]) {
                d[u] = diff + cost;
                Q.push(mp(diff + cost, u));
            }
        }
    }
    return (int64)floor(d[sink]);
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
    	    GA[a][b] = GA[b][a] = c;
    	}
    	for(int i = 0; i < mb; i++) {
    	    int a, b, c;
    	    scanf("%d%d%d", &a, &b, &c);
            GB[a][b] = GB[b][a] = c;
    	}
    	for(int i = 0; i < k; i++) {
    	    double a;
    	    scanf("%lf", &a);
    	    printf("%lld\n", dijkstra(0, n-1, a));
    	}
    }
}
