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
#define ALL(v) (v).begin(), (v).end()

#define INF 1<<30
#define EPS 1e-13

using namespace std;

struct E {
  int from, f, to, tpos;
  E(int fr, int fp, int t, int tp) : from(fr), f(fp), to(t), tpos(tp) {}
  E() {}
};

struct Edge {
  int to, i;
  char color;
  Edge(int t, int x, char c) : to(t), i(x), color(c) {}
};

typedef vector< vector<Edge> > Graph;
typedef pair<int, int> ii;
typedef priority_queue< ii, vector< ii >, greater< ii > > PQ;

const int MAXN = 10e5;

int n, m;
Graph G;
vector<E> L;

int dist[MAXN+10];
int visited[MAXN+10];

int dijkstra(int start, int end) {
  //D(start); D(end);
  fill(&dist[0], &dist[n], INF);
  memset(visited, false, sizeof(visited));

  dist[start] = 0;
  PQ Q;
  Q.push(ii(0, start));
  while(!Q.empty()) {
    ii state = Q.top(); Q.pop();
    int u = state.second;
    int cost = state.first;

    if(visited[u]) continue;
    if(u == end) return cost;

    visited[u] = true;
    FOREACH(e, G[u]) {
      //cerr << "from => " << u;
      //cerr << " to => "<<  e->to << ' ' << e->color << endl;
      if(e->color == 'b') {
        int & d = dist[e->to];
        if(d > cost + 1) {
          d = cost + 1;
          Q.push(ii(d, e->to));
        }
      }
    }
  }
  return -1;
}

int dfs(int i, int end, int sum) {
  if(visited[i]) return INF;
  if(i == end) return sum;
  visited[i] = true;
  int ans = INF;
  FOREACH(e, G[i]) {
    if(visited[e->to]) continue;
    if(e->color == 'b') {
      ans = min(ans, dfs(e->to, end, sum+1));
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  G.resize(n);

  REP(i,n-1) {
    int from, to;
    cin >> from >> to;
    G[from-1].push_back(Edge(to-1, i, 'b'));
    G[to-1].push_back(Edge(from-1, i, 'b'));
    //D(from); D(G[from-1].size());
    L.push_back(E(from-1, G[from-1].size() - 1, to-1, G[to-1].size() - 1));
    //D(L[i].f);
  }

  //D(L.size());

  cin >> m;
  REP(i,m) {
    int type;
    cin >> type;
    if(type == 3) {
      int a, b;
      cin >> a >> b;
      memset(visited, false, sizeof(visited));
      cout << dijkstra(a-1, b-1) << endl;
    }
    else {
      int id;
      cin >> id;
      id--;
      int from = L[id].from;
      int fpos = L[id].f;
      int to = L[id].to;
      int tpos = L[id].tpos;
      //D(id);
      //D(from); D(L[id].f); D(to); D(tpos);
      G[from][fpos].color = G[to][tpos].color = (type == 1)? 'b' : 'w';
      //D(G[from][fpos].color);
    }
  }
}

