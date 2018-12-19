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

const int MAXN = 100 + 10;

bool G1[MAXN][MAXN], G2[MAXN][MAXN];
map< char, int > cities;

int main() {
  int cases, dist = 'Z' - 'A';
  scanf("%d\n", &cases);
  while(cases--) {
    cities.clear();
    int n, m;
    scanf("%d\n", &n);

    fill(&G1[0][0], &G1[MAXN-1][MAXN-1], false);

    REP(i, 0, n) {
      char a, b;
      scanf("%c %c\n", &a, &b);
      
      a = tolower(a), b = tolower(b);

      if(!cities.count( a )) cities[a] = cities.size() - 1;
      if(!cities.count( b )) cities[b] = cities.size() - 1;
      
      int j = cities[a], k = cities[b];
      
      G1[j][k] = G1[k][j] = true;
    }

    scanf("%d\n", &m);

    fill(&G2[0][0], &G2[MAXN-1][MAXN-1], false);

    REP(i, 0, m) {
      char a, b;
      scanf("%c %c\n", &a, &b);

      a = tolower(a), b = tolower(b);

      if(!cities.count( a )) cities[a] = cities.size() - 1;
      if(!cities.count( b )) cities[b] = cities.size() - 1;
      
      int j = cities[a], k = cities[b];

      G2[j][k] = G2[k][j] = true;
    }

    int N = cities.size();

    REP(k, 0, N) REP(i, 0, N) REP(j, 0, N) 
      G1[i][j] = (G1[i][j] or (G1[i][k] and G1[k][j])), 
      G2[i][j] = (G2[i][j] or (G2[i][k] and G2[k][j]));
    //G1[i][j] = min(G1[i][j], G1[i][k] + G1[k][j]), G2[i][j] = min(G2[i][j], G2[i][k] + G2[k][j]);
    
    int ok = true;

    REP(i, 0, N) {
      REP(j, 0, N) {
        //if(G1[i][j] != INF and G2[i][j] != INF) continue; // conection
        if(G1[i][j] and G2[i][j]) continue;
        else if(G1[i][j] != G2[i][j]){
          ok = false;
          break;
        }
      }
      if(!ok) break;
    }

    puts(ok? "YES" : "NO");
    if(cases) puts("");
  }
}

