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

// 762 - We Ship Cheap
// Algorithm : BFS - Backtracking path

map< string, vector<string> > G;
map< string, string > tree;
map< string, bool > visited;
char cityA[10], cityB[10];

int bfs(string A, string B) {
  queue< pair<string, int> > Q;
  Q.push( make_pair(A, 0) );
  visited[A] = true;
  while(!Q.empty()) {
    pair< string, int > s = Q.front();
    Q.pop();

    if(s.first == B) return s.second;

    FOREACH(v, G[s.first]) {
      if(visited.count( *v ) == 0) {
        visited[*v] = true;
        tree[*v] = s.first;
        Q.push( make_pair(*v, s.second + 1) );
      }
    }
  }
  return -1;
}

void print(string dest) {
  if(tree.count( dest ) == 0) return;
  print(tree[dest]);
  printf("%s %s\n", tree[dest].c_str(), dest.c_str());
}

int main() {
  int n, cases = 0;
  while(~scanf("%d", &n)) {
    if(cases++) puts("");
    G.clear();
    tree.clear();
    visited.clear();
    REP(i, 0, n) {
      scanf("%s %s", cityA, cityB);
      G[cityA].push_back(cityB);
      G[cityB].push_back(cityA);
    }
    
    scanf("%s %s", cityA, cityB);

    int ans = bfs(cityA, cityB);
    if(ans == -1) puts("No route");
    else print(cityB);
  }
}

