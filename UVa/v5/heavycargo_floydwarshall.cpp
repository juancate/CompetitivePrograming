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
// Algorith : Floyd Warshall (Maximin)

const int MAXV = 200 + 10;
const int MAXE = 19900 + 10;

map<string, int> mapping;
int G[MAXV][MAXV];
int V, E, T, edges;

char cityA[100], cityB[100];

int main() {
  int cases = 1;
  while(~scanf("%d %d", &V, &E) and (V|E) != 0) {
    mapping.clear();
    memset(G, 0, sizeof(G));

    REP(i, 0, E) {
      int a, b, c;
      scanf("%s %s %d", cityA, cityB, &c);
      if(!mapping.count( cityA )) 
        mapping[cityA] = mapping.size() - 1;
      if(!mapping.count( cityB )) 
        mapping[cityB] = mapping.size() - 1;
      a = mapping[cityA], b = mapping[cityB];

      G[a][b] = G[b][a] = c;
    }

    REP(k, 0, V) REP(i, 0, V) REP(j, 0, V) 
      G[i][j] = max(G[i][j], min(G[i][k], G[k][j])); // pre[i][j] = pre[k][j] if through k is better

    scanf("%s %s", cityA, cityB);    

    printf("Scenario #%d\n", cases++);
    printf("%d tons\n\n", G[mapping[cityA]][mapping[cityB]]);
  }
}

