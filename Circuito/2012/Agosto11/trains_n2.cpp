#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <climits>
#include <cfloat>

#define D(x) cerr << #x << " = " << (x) << endl;

using namespace std;

typedef long long int64;
const int INF = (int)(1e9);
const double EPS = 1e-13;

const int MAXN = 111;

int compareTo(double x, double y, double tol = EPS) {
    return (x <= y + tol)? (x + tol < y)? -1 : 0 : 1;
}

int n;
int GA[MAXN][MAXN], GB[MAXN][MAXN];
double d[MAXN];
bool visited[MAXN];

double calculate_cost(int source, int sink, double a) {
    if(GA[source][sink] != INT_MAX && GB[source][sink] != INT_MAX)
        return (a * GA[source][sink] + (1. - a) * GB[source][sink]);

    return (GA[source][sink] != INT_MAX)? GA[source][sink] : GB[source][sink];
}

int dijkstra(int source, int sink, double a) {
    for(int i = 0; i < n; i++) {
        d[i] = DBL_MAX;
        visited[i] = false;
    }

    d[source] = 0;
    visited[source] = true;

    for(int i = 1; i < n; i++) {
        d[i] = calculate_cost(0, i, a);
    }

    for(int i = 0; i < n; i++) {
        double min_val = DBL_MAX;
        int v = 0;

        for(int j = 0; j < n; j++) {
            if(d[j] < min_val && !visited[j]) {
                v = j;
                min_val = d[j];
            }
        }
        visited[v] = true;

        for(int to = 0; to < n; to++) {
            double cost = calculate_cost(v, to, a);
            if(min_val + cost < d[to]) {
                d[to] = min_val + cost;
            }
        }
    }

    return (int)d[sink];
}

int main() {
    int ma, mb, k;
    while(~scanf("%d%d%d%d", &n, &ma, &mb, &k)) {
    	if(n == -1 && ma == -1 && mb == -1 && k == -1)
    	    break;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                GA[i][j] = GB[i][j] = INT_MAX;
                if(i == j)
                    GA[i][j] = GB[i][j] = 0;
            }
        }

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
    	    printf("%d\n", dijkstra(0, n-1, a));
    	}
    }
}
