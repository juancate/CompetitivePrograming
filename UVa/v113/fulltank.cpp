#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
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

#define D(x) cerr << #x << " = " << x << endl;
#define REP(i,n) for(int i=0; i<n; i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)

#define INF 1<<30
#define EPS 1e-13

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> Edges;
typedef vector<Edges> Graph;
typedef priority_queue<ii, vector<ii>, greater<ii> > p_queue;
typedef vector<int> vi;

int n, m, q, s, e, c, u, v, d;
Graph g, trans;
map<ii, int> table;
int prices[1000+10];
bool terminal[100000];

int dijkstra() {
  int N = trans.size();
  int dist[N], prev[N];
  bool visited[N];
  p_queue pq;

  fill(dist, dist+N, INF);
  memset(prev, -1, sizeof(prev));
  memset(visited, false, sizeof(visited));

  dist[0] = 0;
  pq.push(ii(dist[0], 0));

  while(!pq.empty()) {
    ii state = pq.top(); pq.pop();
    u = state.second;
    int fuel = state.first;

    if(terminal[u]) return dist[u];

    if(visited[u]) continue;
    visited[u] = true;

    FOREACH(it, trans[u]) {
      int x = it->first;
      int cost = it->second;
      if(cost + dist[u] < dist[x]) {
        dist[x] = cost + dist[u];
        prev[x] = u;
        pq.push(ii(dist[x], x));
      }
    }
  }

  return INF;
}

bool transform() { // transform the original graph from start to end
  table.clear();
  trans.clear();
  
  table[ii(s, 0)] = 0;
  trans.push_back(Edges());
  
  bool endfound = false;

  FOREACH(it, table) {
    int x = it->first.first, fuel = it->first.second; // Need where
    Edges& ady = g[x];

    REP(i, ady.size()) {
      int diff = fuel - ady[i].second;
      int y = trans.size();

      if(ady[i].first == e) endfound = true; // connected graph
      
      if(diff < 0 and fuel < c) { // Not enough fuel, full 1 unit if fuel+1 <= c
        if(table.find(ii(x, fuel+1)) == table.end()) {
          table[ii(x, fuel+1)] = y; // stay where i am
          trans.push_back(Edges()); // Add new node
          trans[it->second].push_back(ii(y, prices[x])); // Edge cost 0;
        }
      } else {
        if(table.find(ii(ady[i].first, diff)) == table.end()) {
          table[ii(ady[i].first, diff)] = y; // move to ady[i]
          trans.push_back(Edges()); // Add new node 
          trans[it->second].push_back(ii(y, 0)); // Edge cost 0;
          if(ady[i].first == e) terminal[y] = true;
        }
      }
    }
  }
  return endfound;
}

int main() {
  while(scanf("%d %d", &n, &m) == 2) {
    g.clear();
    g.resize(n);
    REP(i,n) scanf("%d", &prices[i]);
    REP(i,m) {
      scanf("%d %d %d", &u, &v, &d);
      g[u].push_back(ii(v, d));
      g[v].push_back(ii(u, d));
    }
    scanf("%d", &q);
    REP(i,q) {
      scanf("%d %d %d", &c, &s, &e);
      memset(terminal, false, sizeof(terminal));
      if(!transform()) {
        puts("impossible");
        continue;
      }
      /*
      REP(i,trans.size()) {
        cerr << "[" << i << "] => {";
        REP(j, trans[i].size()) {
          if(j) cerr << ",";
          cerr << " (" << trans[i][j].first << ", " << trans[i][j].second << ")";
        }
        cerr << " }"<< endl;
      }
      */
      int ans = dijkstra();
      if(ans == INF) puts("impossible");
      else printf("%d\n", ans);
    }
  }
}

