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

#define D(x) cerr << #x << " = " << x << endl
#define REP(i,n) for(int i=0; i<n; i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)

#define INF 1<<30
#define EPS 1e-13

// 10147 - Highways
// Algorithm: Prim's MST

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> Graph;
typedef priority_queue<ii, vector<ii>, greater<ii> > p_queue;

int graph[800][800];
bool conected[800][800], visited[800];
int parent[800], points[800][2];
Graph tree;

int t, n, m;

int distanc(int x, int y) {
  return ((x*x) + (y*y));
}

void prim() {
  int dist[n];
  bool visited[n];
  fill(&dist[0], &dist[n-1], INF);
  memset(visited, false, sizeof(visited));
  tree.clear();
  tree.resize(n);

  dist[0] = 0;
  
  REP(j, n) {
    int u = -1;
    REP(i, n) if(!visited[i] and (u == -1 || dist[i] < dist[u])){
      u = i;
    }

    if(dist[u] == INF) {
      cerr << "Error!";
      return;
    }

    visited[u] = true;
    //if(parent[u] != -1) cerr << (u+1) << " " << (parent[u]+1) << endl;
    REP(v, n) {
      if(v != u and dist[v] > graph[u][v]) {
        parent[v] = u;
        dist[v] = graph[u][v];

        tree[u].push_back(v);
        tree[v].push_back(u);
      }
    }
  }               
}

void dfs(int node, int p) {
  parent[node] = p;
  visited[node] = true;
  FOREACH(it, tree[node]) if(!visited[*it])
    dfs(*it, node);
}

int main() {
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);

    REP(i, n) scanf("%d %d", &points[i][0], &points[i][1]); // x, y
    
    memset(graph, 0, sizeof(graph));
    memset(conected, false, sizeof(conected));
    memset(visited, false, sizeof(visited));
    memset(parent, -1, sizeof(parent));
    
    REP(i, n) REP(j, n) if(i != j){
      int d = distanc((points[i][0] - points[j][0]), (points[i][1] - points[j][1]));
      graph[i][j] = graph[j][i] = d;
    }
    
    scanf("%d", &m);
    REP(i, m) {
      int a, b;
      scanf("%d %d", &a, &b);
      graph[a-1][b-1] = graph[b-1][a-1] = -INF;
      conected[a-1][b-1] = conected[b-1][a-1] = true;
    }
    /*
    REP(i, n) {
      REP(j, n) {
        if(j) cerr << " ";
        cerr << graph[i][j];
      }
      cerr << endl;
    }
    */
    prim();
    dfs(0,-1);
    
    bool full = true;
    REP(i, n) if(parent[i] != -1 and !conected[i][parent[i]]) {
      printf("%d %d\n", (i+1), (parent[i]+1));
      full = false;
    }
    if(full) puts("No new highways need");
    
    D(graph[5-1][9-1]);
    D(graph[9-1][5-1]);

    if(t) puts("");
  }
}

