#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <stdbool.h>

typedef long long int64;

#define MAXN 111

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
    int i, j, to, v;
    double min_val, cost;

    for(i = 0; i < n; i++) {
        d[i] = DBL_MAX;
        visited[i] = false;
    }

    d[source] = 0;
    visited[source] = true;

    for(i = 1; i < n; i++) {
        d[i] = calculate_cost(0, i, a);
    }

    for(i = 0; i < n; i++) {
        min_val = DBL_MAX;
        v = 0;

        for(j = 0; j < n; j++) {
            if(d[j] < min_val && !visited[j]) {
                v = j;
                min_val = d[j];
            }
        }
        visited[v] = true;

        for(to = 0; to < n; to++) {
            cost = calculate_cost(v, to, a);
            if(min_val + cost < d[to]) {
                d[to] = min_val + cost;
            }
        }
    }

    return (int)d[sink];
}

int main() {
    int ma, mb, k, a, b, c, i, j, l;
    double x;
    while(~scanf("%d%d%d%d", &n, &ma, &mb, &k)) {
    	if(n == -1 && ma == -1 && mb == -1 && k == -1)
    	    break;

        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                GA[i][j] = GB[i][j] = INT_MAX;
                if(i == j)
                    GA[i][j] = GB[i][j] = 0;
            }
        }

    	for(i = 0; i < ma; i++) {
    	    scanf("%d%d%d", &a, &b, &c);
    	    GA[a][b] = GA[b][a] = c;
    	}
    	for(i = 0; i < mb; i++) {
    	    scanf("%d%d%d", &a, &b, &c);
            GB[a][b] = GB[b][a] = c;
    	}

    	for(l = 0; l < k; l++) {
    	    scanf("%lf", &x);
    	    printf("%d\n", dijkstra(0, n-1, x));
    	}
    }
    return 0;
}
