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

#define row first.first
#define col first.second
#define level second.first
#define minutes second.second

typedef pair<int, int> ii;
typedef pair<ii, ii> State;

#define State(r, c, l, m) make_pair(make_pair(r, c), make_pair(l, m))

const int MAXN = 30 + 5;
const int MOVES = 6;
const int dr[] = {0, 1, 0, -1, 0, 0};
const int dc[] = {1, 0, -1, 0, 0, 0};
const int dl[] = {0, 0, 0, 0, 1, -1};

int L, R, C;
char board[MAXN][MAXN][MAXN];
bool visited[MAXN][MAXN][MAXN];

bool valid(int r, int c, int l) {
  return (r >= 0 and r < R and c >= 0 and c < C and l >= 0 and l < L and board[r][c][l] != '#' );
}

int bfs(int r, int c, int l) {
  queue< State > Q;
  Q.push(State(r, c, l, 0));
  memset(visited, false, sizeof(visited));

  while(!Q.empty()) {
    State s = Q.front(); Q.pop();

    if(visited[s.row][s.col][s.level]) continue;
    if(board[s.row][s.col][s.level] == 'E') return s.minutes;

    visited[s.row][s.col][s.level] = true;

    REP(i, MOVES) {
      int nr = s.row + dr[i];
      int nc = s.col + dc[i];
      int nl = s.level + dl[i];

      if(valid(nr, nc, nl) and !visited[nr][nc][nl]) {
        Q.push(State(nr, nc, nl, s.minutes + 1));
      }
    }
  }
  return -1;
}

int main() {
  while(scanf("%d %d %d\n", &L, &R, &C) == 3 and (L|R|C) != 0) {
    int r, c, l;
    REP(i, L) {
      REP(j, R) {
        REP(k, C) {
          scanf("%c", &board[j][k][i]);
          if(board[j][k][i] == 'S') l = i, r = j, c = k;
        }
        scanf("\n");
      }
      scanf("\n");
    }

    int ans = bfs(r, c, l);
    if(ans == -1) puts("Trapped!");
    else printf("Escaped in %d minute(s).\n", ans);
  }
}

