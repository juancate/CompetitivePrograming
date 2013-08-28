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
#define FOREACH(it,v) for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

struct Edge {
  int u, v, c;
} edges[5010];

vector< pair<int,int> > g[110];

int n, m, source, sink, V, p[256];
long long cap[256][256], flow[256][256];

void add_edge(int u, int v, int c, int f) {
  cap[u][v] = f; flow[u][v] = c;
  cap[v][u] = 0; flow[v][u] = -c;
}

long long augmenting_path(int s, int t, long long f) {
  int i = t;
  long long cost = 0;
  while(p[i] != -1) {
    cap[p[i]][i] -= f;
    cost += f * flow[p[i]][i];
    cap[i][p[i]] += f;
    i = p[i];
  }
  return cost;
}

long long dijkstra(int s, int t) {
  vector<long long> dist(V, INF), f(V, 0);
  dist[s] = 0;
  f[s] = INF;
  memset(p, -1, sizeof p);
  priority_queue< pair<long long,int>,
    vector< pair<long long,int> >, greater< pair<long long,int> > > pq;
  pq.push(make_pair(0, s));

  while(!pq.empty()) {
    pair<long long,int> front = pq.top(); pq.pop();
    long long d = front.first; int u = front.second;
    if(d == dist[u]) {
      for(int v = 0; v < V; v++) {
        if(cap[u][v] > 0 && flow[u][v] + dist[u] < dist[v]) {
          dist[v] = flow[u][v] + dist[u];
          f[v] = min(f[u], cap[u][v]);
          p[v] = u;
          pq.push(make_pair(dist[v], v));
        }
      }
    }
  }
  return f[t];
}

long long bellman_ford(int s, int t) {
  vector<long long> dist(V, INF), f(V, 0);
  dist[s] = 0;
  f[s] = INF;
  memset(p, -1, sizeof p);
  for(int i = 0; i < V-1; i++) {
    for(int u = 0; u < V; u++) {
      for(int v = 0; v < V; v++) {
        if(cap[u][v] > 0 && flow[u][v] + dist[u] < dist[v]) {
          dist[v] = flow[u][v] + dist[u];
          f[v] = min(f[u], cap[u][v]);
          p[v] = u;
        }
      }
    }
  }
  //D(f[t]);
  return f[t];
}

long long minCostMaxFlow(long long d) {
  long long mc;
  mc = 0;

  while(d > 0) {
    long long f = dijkstra(source, sink);
    if(f == 0) return -1;

    //D(d);
    mc += augmenting_path(source, sink, min(f, d));
    //D(f);
    d -= f;
  }

  if(d == 0)
    return mc;
  return -1;
}

int main() {
  while(scanf("%d%d", &n, &m) != EOF) {
    for(int i = 0; i < m; i++) {
      int u, v, c;
      scanf("%d%d%d", &u, &v, &c);
      g[u].push_back(make_pair(v, c));
      g[v].push_back(make_pair(u, c));
      edges[i].u = u; edges[i].v = v; edges[i].c = c;
    }
    memset(cap, 0, sizeof cap);
    memset(flow, 0, sizeof flow);

    int D, K;
    scanf("%d%d", &D, &K);

    V = n+n+2;
    source = 0;
    sink = V-1;
    add_edge(source, 1, 0, D);
    add_edge(n, sink, 0, D);

    for(int i = 0; i < m; i++) {
      add_edge(edges[i].u, edges[i].v, edges[i].c, K);
      add_edge(n+edges[i].v, n+edges[i].u, edges[i].c, K);
    }

    long long ans = minCostMaxFlow(D);

    if(ans < 0) printf("Impossible.\n");
    else printf("%lld\n", ans);
  }
  return 0;
}

