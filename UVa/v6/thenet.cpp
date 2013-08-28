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
#include <limits>

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

char line[1111], *_stk = NULL;

int readint() {
  if(_stk == NULL) {
    if(!gets(line)) exit(0);
    _stk = strtok(line, ",- ");
  }
  if(_stk != NULL) {
    int num = atoi(_stk);
    _stk = strtok(NULL, ",- ");
    return num;
  }
  return numeric_limits<int>::max();
}

const int MAXN = 300 + 10;

vector<int> G[MAXN];
bool visited[MAXN];
int tree[MAXN];

bool bfs(int start, int end) {
  memset(visited, false, sizeof(visited));
  memset(tree, -1, sizeof(tree));
  queue< int > Q;
  Q.push(start);
  visited[start] = true;
  while(!Q.empty()) {
    int s = Q.front(); Q.pop();

    if(s == end) return true;

    FOREACH(v, G[s]) {
      if(!visited[*v]) {
        Q.push( *v );
        tree[*v] = s;
        visited[*v] = true;
      }
    }
  }
  return false;
}

void printPath(int node, int goal) {
  if(node == goal) {
    printf("%d", node);
    return;
  }
  printPath(tree[node], goal);
  printf(" %d", node);
}

int main() {
  while(true) {
    int n = readint();

    REP(i, n+1) G[i].clear();
    REP(i, n) {
      int u = readint();      
      while(_stk != NULL)  {
        int v = readint();
        G[u].push_back(v);
      }
    }
    int m = readint();
    puts("-----");
    REP(i,m) {
      int start = readint(), end = readint();
      if(bfs(start, end)) printPath(end, start);
      else printf("connection impossible");
      puts("");
    }
  }
}

