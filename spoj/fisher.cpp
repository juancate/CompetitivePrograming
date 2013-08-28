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

#define D(x) cerr << #x << " = " << x << endl;
#define REP(i,n) for(int i=0; i<n; i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

#define INF 1<<30
#define EPS 1e-13

using namespace std;

const int MAXN = 50 + 10;

bool visited[MAXN];
int times[MAXN][MAXN];
int tolls[MAXN][MAXN];

int N, T;

struct State {
  int port, time, toll, spent;
  State(int p, int t, int to, int s) : port(p), time(t), toll(to), spent(s) {}
  State();
  bool operator<(const State& s) const { return toll < s.toll; }
  bool operator>(const State& s) const { return toll > s.toll; }
  void print() { 
    cerr << "port => " << port << " toll => " << toll << " spent => " << spent;
    cerr << " left => " << time << "\n";
  }
};

typedef priority_queue<State, vector<State>, greater<State> > PQ;

pair<int, int> uniformCost() {
  memset(visited, false, sizeof(visited));
  PQ Q;
  Q.push(State(0, T, 0, 0));
  pair<int, int> ret;
  while(!Q.empty()) {
    State s = Q.top(); Q.pop();
    if(s.port == N-1) {
      ret = make_pair(s.toll, s.spent);
      break;
    }
    visited[s.port] = true;
    REP(i,N) {
      if(i == s.port) continue;
      int t = s.time - times[s.port][i];
      int toll = s.toll + tolls[s.port][i];
      if(t >= 0) {
        State son = State(i, t, toll, s.spent + times[s.port][i]);
        Q.push(son);
      }
    }
  }
  return ret;
}

int main() {
  while(true) {
    scanf("%d %d", &N, &T);
    if((N|T) == 0) break;
    REP(i,N) REP(j,N) scanf("%d", &times[i][j]);
    REP(i,N) REP(j,N) scanf("%d", &tolls[i][j]);
    pair<int, int> ans = uniformCost();
    printf("%d %d\n", ans.first, ans.second);
  }
}

