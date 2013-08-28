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

const int MAXN = 1000 + 10;

// Problem : 5804 - Route Redundancy (LiveArchive)
// Algorithm : Max Flow (Edmonds-Karp) with PFS (Dijkstra)

int source, sink, N, E;
int capacity[MAXN][MAXN], parent[MAXN];
vector< vector<int> > G;
bool visited[MAXN];

struct State {
  int v, priority, from;
  State(int i, int p, int f) : v(i), priority(p), from(f) {}
  bool operator >(const State b) const {
    return priority > b.priority;
  }
  bool operator <(const State b) const {
    return priority < b.priority;
  }
};

// Calculate augmenting path with PFS (Dijkstra modified)
int pfs() {
  priority_queue<State> PQ;
  memset(visited, 0, sizeof(visited));
  memset(parent, -1, sizeof(parent));

  PQ.push(State(source, INF, -1));

  int path_capacity = 0;
  int where, next, cost;

  while(!PQ.empty()) {
    State u = PQ.top();
    PQ.pop();
    where = u.v, cost = u.priority;

    if(visited[where]) continue;
    parent[where] = u.from;

    if(where == sink) {
      path_capacity = cost;
      break;
    }

    visited[where] = true;

    REP(i, 0, G[where].size()) {
      next = G[where][i];
      if(capacity[where][next] > 0) {
        int new_cost = min(cost, capacity[where][next]);
        PQ.push(State(next, new_cost, where));
      }
    }
  }

  if(path_capacity == 0) return 0;

  where = sink;

  while(parent[where] != -1) {
    int prev = parent[where];
    capacity[prev][where] -= path_capacity;
    capacity[where][prev] += path_capacity;
    where = prev;
  }
  return path_capacity;
}

void maxflow(int id) {
  int max_flow = 0;
  int first_flow = 0;
  bool first = true;

  while(true) {
    int flow = pfs();
    if(first) {
      first_flow = flow;
      first = false;
    }
    if(flow == 0)
      break;
    max_flow += flow;
  }
  double ans = ((double)max_flow / (double)first_flow);

  printf("%d %.3lf\n", id, ans);
}

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    int id;
    scanf("%d %d %d %d %d", &id, &N, &E, &source, &sink);

    //memset(capacity, 0, sizeof(capacity));
    G.clear();
    G.resize(N);

    REP(i, 0, E) {
      int a, b, c;
      scanf("%d %d %d", &a, &b, &c);
      capacity[a][b] = c;
      G[a].push_back(b);
      G[b].push_back(a);
    }

    maxflow(id);
  }
}

