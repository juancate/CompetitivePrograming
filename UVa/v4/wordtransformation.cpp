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

const int MAXN = 10 + 10;

map< string, vector<string> > G;
map< string, bool > visited;

char A[MAXN], B[MAXN];

int cmp(string a, string b) {
  int n = a.length();
  int m = b.length();

  if(n != m) return -1;  

  int cnt = 0;
  REP(i, 0, n) {
    if(a[i] != b[i]) cnt++;
    if(cnt > 1) return -1;
  }
  return cnt;
}

int bfs(string A, string B) {
  visited.clear();
  queue< pair<string, int> > Q;
  Q.push( make_pair(A, 0) );
  visited[A] = true;

  while(!Q.empty()) {
    pair<string, int> s = Q.front(); 
    Q.pop();

    if(s.first == B) return s.second;
    
    FOREACH(v, G[s.first]) {
      if(!visited[*v]) {
        visited[*v] = true;
        Q.push( make_pair(*v, s.second + 1) );
      }
    }
  }
  
  return -1;
}

int main() {
  int cases;
  scanf("%d\n", &cases);
  while(cases--) {
    G.clear();
    while(gets(A) and A[0] != '*') {
      G[A];
      FOREACH(it, G) {
        if(cmp(it->first, A) == 1) {
          G[A].push_back(it->first);
          G[it->first].push_back(A);
        }
      }
    }

    char line[MAXN * MAXN];
    while(gets(line) and strlen(line) != 0) {
      sscanf(line, "%s %s", A, B);
      int ans = bfs(A, B);
      printf("%s %s %d\n", A, B, ans);
    }
    if(cases) puts("");
  }
}

