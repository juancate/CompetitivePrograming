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

const int MAXN = 182+10;
const int dr[] = { 1, 0, -1, 0};
const int dc[] = { 0, 1, 0, -1};

int T, N, M;
int distances[MAXN][MAXN], board[MAXN][MAXN];
queue< pair<int, int> > Q;

char line[MAXN];

bool valid(int r, int c) {
  return (r >= 0 and r < N and c >= 0 and c < M);
}

void bfs() {
  while(!Q.empty()) {
    pair<int, int> p = Q.front(); Q.pop();
    int d = distances[p.first][p.second];
    REP(i, 4) {
      int nr = p.first + dr[i];
      int nc = p.second + dc[i];
      if(valid(nr, nc) and distances[nr][nc] > d + 1) {
        distances[nr][nc] = d + 1;
        Q.push(make_pair(nr, nc));
      }
    }
  }
}

int main() {
  scanf("%d", &T);
  while(T--) {
    scanf("%d %d", &N, &M);
    fill(&distances[0][0], &distances[N][M], INF);
    REP(i, N) {
      scanf("%s", line);
      REP(j, M) { 
        board[i][j] = line[j] - '0';
        if(board[i][j] == 1) {
          Q.push(make_pair(i, j));
          distances[i][j] = 0;
        }
      }
    }
    bfs();
    REP(i, N) {
      REP(j, M) {
        if(j) printf(" ");
        printf("%d", distances[i][j]);
      }
      puts("");
    }
  }
}

