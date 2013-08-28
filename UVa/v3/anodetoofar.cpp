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

const int INF = 100000000;
const long long INFLL = 1000000000000000000LL;
const double EPS = 1e-13;

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> Graph;

const int MAXN = 31;

int NC, cnt;
map<int, int> mapping;
bool visited[MAXN];
vi G[MAXN];

void bfs(int start, int ttl) {
  queue<ii> Q;
  Q.push(ii(start, ttl));

  while(!Q.empty()) {
    ii state = Q.front(); Q.pop();

    if(visited[state.first]) continue;
    visited[state.first] = true;
    cnt++;

    if(state.second == 0) continue;

    FOREACH(v, G[state.first])
      if(!visited[*v])
        Q.push(ii(*v, state.second - 1));
  }
}

int main() {
  int cases = 1;
  while(scanf("%d", &NC) == 1 and NC != 0) {
    mapping.clear();
    REP(i, MAXN) G[i].clear();
    REP(i,NC) {
      int from, to;
      scanf("%d %d", &from, &to);
      if(mapping.count(from) == 0) {
        mapping[from] = mapping.size() - 1;
      }
      if(mapping.count(to) == 0) {
        mapping[to] = mapping.size() - 1;
      }
      from = mapping[from], to = mapping[to];
      G[from].push_back(to);
      G[to].push_back(from);
    }

    int start, ttl, size;
    size = mapping.size();
    while(scanf("%d %d", &start, &ttl) == 2 and (start|ttl) != 0) {
      memset(visited, false, sizeof(visited));
      cnt = 0;
      bfs(mapping[start], ttl);
      int ans = size - cnt;
      printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", 
             cases++, ans, start, ttl);
    }
  }
}

