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

//Algorithm: Dijkstra with multiple States for node

struct State;

typedef pair<int, int> ii;
typedef vector<ii> Edge;
typedef vector<Edge> Graph;
typedef priority_queue<State, vector<State>, greater<State> > PQ;

const int MAXN = 1000;

int n, m, q, s, e, c;
int prices[MAXN+10];
int d[MAXN+10][100+10];
bool visited[MAXN+10][100+10];
Graph g; 

struct State {
  int node, fuel, cost;
  State(int n, int f, int c): node(n), fuel(f), cost(c) { }
  bool operator>(const State& a) const {
    return cost > a.cost;
  }
};

int dijkstra() {
  REP(i,n) REP(j,c+1) d[i][j] = INF, visited[i][j] = false;
  
  d[s][0] = 0;

  PQ pq;
  pq.push(State(s, 0, 0));

  while(!pq.empty()) {
    State u = pq.top(); pq.pop();

    if(u.node == e and u.fuel == 0) return u.cost;
    if(visited[u.node][u.fuel]) continue;

    visited[u.node][u.fuel] = true;
    /*
    // Create other states, when I just buy fuel
    int cost = u.cost; // current cost of fuel
    for(int f = u.fuel+1; f <= c; f++) { // try to fill until reach capacity c
      cost += prices[u.node];
      int& bcost = d[u.node][f];
      if(bcost > cost) {
        bcost = cost;
        pq.push(State(u.node, f, cost));
      }
    }*/

    FOREACH(el, g[u.node]) {
      if(el->second <= u.fuel) {
        int nfuel = u.fuel - el->second;
        if(u.cost < d[el->first][nfuel]) {
          d[el->first][nfuel] = u.cost;
          pq.push(State(el->first, nfuel, u.cost));
        }
      } else if(u.fuel < c) {
        int cost = u.cost + prices[u.node];
        int& bcost = d[u.node][u.fuel+1];
        if(bcost > cost) {
          bcost = cost;
          pq.push(State(u.node, u.fuel+1, cost));
        }
      }
    }
  }

  return INF;
}

int main() {
  scanf("%d %d", &n, &m);
  REP(i,n) scanf("%d", &prices[i]);
  g.clear();
  g.resize(n);
  REP(i, m) {
    int from, to, d;
    scanf("%d %d %d", &from, &to, &d);
    g[from].push_back(ii(to, d));
    g[to].push_back(ii(from, d));
  }
  scanf("%d", &q);
  REP(i, q) {
    scanf("%d %d %d", &c, &s, &e);
    int ans = dijkstra();
    if(ans == INF) puts("impossible");
    else printf("%d\n", ans);
  }
}

