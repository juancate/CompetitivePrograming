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
#define REP(i,n) for(int i=0; i<n; i++)
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
  REP(i,z.size())os << z[i] << ", " ;
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

//////////////////////////////////////////////////////////////////////////////////////////

// Problem: 10462 - Is There A Second Way Left ?
// Algorithm: MST Kruskal

typedef pair< pair< int, int >, pair< int, int > > Edge; // Edge - cost, index, from, to
typedef priority_queue< Edge, vector< Edge >, greater< Edge > > PriorityQueue;

#define Edge(c, i, f, t) make_pair(make_pair(c, i), make_pair(f, t))
#define cost first.first
#define index first.second
#define from second.first
#define to second.second

const int MAXV = 100 + 10;
const int MAXE = 200 + 10;

Edge graph[MAXE];
int pset[MAXV], rank[MAXV], size[MAXV];
vector<int> used; // mark edges in MST
int V, E, T, edges;

void init() {
  REP(i, V+1) pset[i] = i, rank[i] = 0, size[i] = 1;
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

int kruskal(bool mode) {
  init();
  int ans = 0;
  edges = 0;
  PriorityQueue pq;
  REP(i, E) pq.push(graph[i]);

  while(!pq.empty()) {
    if(edges == V-1) break;
    Edge s = pq.top(); pq.pop();
    int a = find(s.from);
    int b = find(s.to);

    if(a != b) {
      ans += s.cost;
      if(mode) used.push_back(s.index);
      unionSet(a, b);
      edges++;
    }
  }
  return ans;
}

int main() {
  scanf("%d", &T);
  for(int cases = 1; cases <= T; cases++) {
    scanf("%d %d", &V, &E);

    REP(i, E) {
      int c, f, t;
      scanf("%d %d %d", &f, &t, &c);
      graph[i] = Edge(c, i, f, t);
    }

    used.clear();
    kruskal(true);

    if(edges != V-1) { // Not a tree
      printf("Case #%d : No way\n", cases);
      continue;
    }
    int secondway = INF;
    FOREACH(it, used) {
      int c = graph[*it].cost;
      graph[*it].cost = INF;
      int ans = kruskal(false);
      graph[*it].cost = c;
      if(edges == V-1) 
        secondway = min(secondway, ans);
    }
    if(secondway == INF)
      printf("Case #%d : No second way\n", cases);
    else
      printf("Case #%d : %d\n", cases, secondway);
  }
}

