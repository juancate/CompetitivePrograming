#include <bits/stdc++.h>

using namespace std;

const int MAXN = 111;

int n;
int GA[MAXN][MAXN], GB[MAXN][MAXN];
double d[MAXN];

#define mp make_pair

int dijkstra(int source, int sink, double a) {
  for(int i = 0; i < n; i++) d[i] = 1e50;

  d[source] = 0;
  priority_queue< pair<double, int>, vector< pair<double, int> >, greater< pair<double, int> > > Q;
  Q.push( mp(0.0, source) );

  while (!Q.empty()) {
    int v = Q.top().second;
    double cost = Q.top().first;
    Q.pop();

    if (cost > d[v])
      continue;
    if (v == sink)
      return floor(cost);

    for (int u = 0; u < n; u++) {
      if (GA[v][u] == -1 && GB[v][u] == -1)
        continue;

      double diff;
      if (GA[v][u] != -1 && GB[v][u] != -1)
        diff = a * GA[v][u] + (1. - a) * GB[v][u];
      else
        diff = max(GA[u][v], GB[v][u]);

      if (diff + cost < d[u]) {
        d[u] = diff + cost;
        Q.push(mp(diff + cost, u));
      }
    }
  }
  return -1;
}

int main() {
  int ma, mb, k;
  while (scanf("%d%d%d%d", &n, &ma, &mb, &k)) {
    if(n == -1 && ma == -1 && mb == -1 && k == -1)
      break;

    memset(GA, -1, sizeof(GA));
    memset(GB, -1, sizeof(GB));

    for (int i = 0; i < ma; i++) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      GA[a][b] = GA[b][a] = c;
    }

    for (int i = 0; i < mb; i++) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      GB[a][b] = GB[b][a] = c;
    }

    for (int i = 0; i < k; i++) {
      double a;
      scanf("%lf", &a);
      printf("%d\n", dijkstra(0, n-1, a));
    }
  }
}
