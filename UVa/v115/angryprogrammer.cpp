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

#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

const int INF = 1000000000;
const long long INFLL = 1000000000000000000LL;
const double EPS = 1e-13;

// Problem : 11506 - Angry Programmer
// Algorithm : Min-cut max flow (Vertex with capacity) Edmonds-Karp

const int MAXN = 100 + 10;

int source, sink, N, E, m, w;
int residual[MAXN][MAXN], parent[MAXN];
vector< vector<int> > G;
bool visited[MAXN];

// Calculate augmenting path with BFS
int bfs() {
  queue<int> Q;

  memset(parent, -1, sizeof(parent));
  memset(visited, false, sizeof(visited));

  Q.push(source);
  visited[source] = true;

  while(!Q.empty()) {
    int where = Q.front();
    Q.pop();

    bool sink_found = false;
    REP(next, 0, N) {
    //REP(i, 0, G[where].size()) {
      //int next = G[where][i];
      if(!visited[next] and residual[where][next] > 0) {
        Q.push(next);
        visited[next] = true;
        parent[next] = where;

        if(next == sink) {
          sink_found = true;
          break;
        }
      }
    }

    if(sink_found) break;
  }

  int where = sink, path_capacity = INF;

  while(parent[where] != -1) {
    int prev = parent[where];
    path_capacity = min(path_capacity, residual[prev][where]);
    where = prev;
  }

  if(path_capacity == INF) return 0;

  where = sink;

  while(parent[where] != -1) {
    int prev = parent[where];
    residual[prev][where] -= path_capacity;
    residual[where][prev] += path_capacity;
    where = prev;
  }

  return path_capacity;
}

int maxflow() {
  int ret = 0;

  while(true) {
    int flow = bfs();
    if(flow == 0)
      break;
    ret += flow;
  }

  return ret;
}

int main() {
  while(~scanf("%d %d", &m, &w) and (m|w) != 0) {
    N = 2 * m;

    memset(residual, 0, sizeof(residual));

    G.clear();
    G.resize(N);

    // vertex m - 1 + 1 == server because 2*m vertex
    residual[0][m] = residual[m-1][m + m - 1] = INF; // from in to out

    G[0].push_back(m);
    G[m-1].push_back(m + m - 1);

    source = 0, sink = m + m - 1;

    REP(i, 0, m - 2) {
      int a, b;
      scanf("%d %d", &a, &b);
      a--;
      residual[a][m + a] = b;
      G[a].push_back(m + a);
    }

    REP(i, 0, w) {
      int a, b, c;
      scanf("%d %d %d", &a, &b, &c);
      a--, b--;
      residual[m + a][b] = residual[m + b][a] = c; // part from out
      G[m + a].push_back(b);
      G[m + b].push_back(a);
    }

    //D(G);

    int ans = maxflow();
    printf("%d\n", ans);
  }
}

