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

#define D(x) cerr << #x << " = " << (x) << endl;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

template<typename T,typename U> inline
std::ostream& operator<<(std::ostream& os, const pair<T,U>& z){
  return ( os << "(" << z.first << ", " << z.second << ",)" );
}
template<typename T> inline
std::ostream& operator<<(std::ostream& os, const vector<T>& z){
  os << "[ ";
  REP(i,0,z.size())os << z[i] << ", " ;
  return ( os << "]" << endl);
}
template<typename T> inline
std::ostream& operator<<(std::ostream& os, const set<T>& z){
  os << "set( ";
  FOREACH(p,z)os << (*p) << ", " ;
  return ( os << ")" << endl);
}
template<typename T,typename U> inline
std::ostream& operator<<(std::ostream& os, const map<T,U>& z){
  os << "{ ";
  FOREACH(p,z)os << (p->first) << ": " << (p->second) << ", " ;
  return ( os << "}" << endl);
}

const int INF = 1000000000;
const long long INFLL = 1000000000000000000LL;
const double EPS = 1e-13;

// 544 - Heavy Cargo
// Algorithm: MST (Maximum spanning tree)

typedef pair< int, pair< int, int > > Edge; // Edge - cost, from, to
typedef priority_queue< Edge > PriorityQueue;

#define Edge(c, f, t) make_pair(c, make_pair(f, t))
#define cost first
#define from second.first
#define to second.second

const int MAXV = 200 + 10;
const int MAXE = 19900 + 10;

Edge graph[MAXE];
map<string, int> mapping;
int pset[MAXV], rank[MAXV], size[MAXV], G[MAXV][MAXV], tree[MAXV];
bool visited[MAXV];
int V, E, T, edges;

char cityA[100], cityB[100];

void init() {
  REP(i, 0, V+1) pset[i] = i, rank[i] = 0, size[i] = 1;
}

int find(int x) {
  return (pset[x] == x)? x : (pset[x] = find(pset[x]));
}

void unionSet(int x, int y) {
  int xr = find(x), yr = find(y);

  if(xr == yr) 
    return;

  if(rank[xr] < rank[yr]) {
    pset[xr] = yr;
    size[yr] += size[xr];
  } 
  else {
    pset[yr] = xr;
    size[xr] += size[yr];
    if(rank[xr] == rank[yr]) rank[xr]++;
  }
}

int kruskal() {
  init();
  int ans = INF;
  edges = 0;
  PriorityQueue pq;
  REP(i, 0, E) pq.push(graph[i]);
  //vector< pair<int, int> > ret;

  while(!pq.empty()) {
    if(edges == V-1) break;
    Edge s = pq.top(); pq.pop();
    int a = find(s.from);
    int b = find(s.to);

    if(a != b) {
      ans = min(ans, s.cost);
      unionSet(a, b);
      edges++;
      G[s.from][s.to] = G[s.to][s.from] = s.cost;
      //ret.push_back(make_pair(s.from, s.to));
    }
  }
  return ans;
}

void dfs(int node, int parent) {
  tree[node] = parent;
  visited[node] = true;
  REP(j, 0, V) if(G[node][j] != -1 and !visited[j]) {
    dfs(j, node);
  }
}

int main() {
  int cases = 1;
  while(~scanf("%d %d", &V, &E) and (V|E) != 0) {
    mapping.clear();
    memset(G, -1, sizeof(G));
    memset(visited, false, sizeof(visited));

    REP(i, 0, E) {
      int a, b, c;
      scanf("%s %s %d", cityA, cityB, &c);

      if(!mapping.count( cityA )) 
        mapping[cityA] = mapping.size() - 1;
      if(!mapping.count( cityB )) 
        mapping[cityB] = mapping.size() - 1;

      a = mapping[cityA], b = mapping[cityB];
      graph[i] = Edge(c, a, b);
    }

    scanf("%s %s", cityA, cityB);
    kruskal();
    dfs(mapping[cityA], -1);

    int ans = INF;
    for(int i = mapping[cityB]; tree[i] != -1; i = tree[i]) 
      ans = min(ans, G[i][tree[i]]);    
    
    printf("Scenario #%d\n", cases++);
    printf("%d tons\n\n", ans);
  }
}

