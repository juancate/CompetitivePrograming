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

int M, N;
map< string, vector<string> > G;
map< string, bool > visited;
map< string, string > parent;

char cityA[MAXN], cityB[MAXN];

void bfs(string a, string b) {
  visited.clear();
  parent.clear();

  queue<string> Q;

  Q.push(a);
  visited[a] = true;

  while(!Q.empty()) {
    string s = Q.front(); 
    Q.pop();

    if(s == b) break;

    FOREACH(v, G[s]) {
      if(!visited[*v]) {
        parent[*v] = s;
        visited[*v] = true;
        Q.push(*v);
      }
    }
  }
}

void printPath(string n) {
  if(!parent.count(n)) {
    printf("%c", n[0]);
    return;
  }
  printPath(parent[n]);
  printf("%c", n[0]);
}

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    G.clear();
    scanf("%d %d", &M, &N);

    REP(i, 0, M) {
      scanf("%s %s", cityA, cityB);
      G[cityA].push_back(cityB);
      G[cityB].push_back(cityA);
    }
    
    REP(i, 0, N) {
      scanf("%s %s", cityA, cityB);
      bfs(cityA, cityB);
      printPath(cityB);
      puts("");
    }

    if(T) puts("");
  }
}

