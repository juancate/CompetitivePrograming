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
#define FOREACH(it,v) for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

const int maxn = 110;

int a[maxn], b[maxn], parent[maxn+maxn], used[maxn+maxn], n, m;
int residual[maxn+maxn][maxn+maxn], source, sink, N;

int augmenting_path() {
  int where, path_capacity;

  where = sink;
  path_capacity = INF;

  while(parent[where] != -1) {
    int prev = parent[where];
    path_capacity = min(path_capacity, residual[prev][where]);
    where = prev;
  }

  if(path_capacity == INF) return 0;

  where = sink;

  while(parent[where] != -1) {
    int prev = parent[where];
    residual[prev][where] -= path_capacity;
    residual[where][prev] += path_capacity;
    where = prev;
  }

  return path_capacity;
}

int bfs() {
  queue<int> q;
  int where, next;

  memset(parent, -1, sizeof parent);
  memset(used, 0, sizeof used);

  q.push(source);
  used[source] = true;

  while(!q.empty()) {
    where = q.front();
    q.pop();

    bool sink_found = false;
    for(next = 0; next < N; next++) {
      if(!used[next] && residual[where][next] > 0) {
        q.push(next);
        used[next] = true;
        parent[next] = where;

        if(next == sink) {
          sink_found = true;
          break;
        }
      }
    }
    if(sink_found) break;
  }
  return augmenting_path();
}

int max_flow() {
  int mf = 0;

  while(true) {
    int flow = bfs();
    if(flow == 0) break;
    mf += flow;
  }
  return mf;
}

int main() {
  int t;
  scanf("%d", &t);

  for(int case_id = 1; case_id <= t; case_id++) {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
      scanf("%d", &a[i]);

    scanf("%d", &m);
    for(int i = 1; i <= m; i++)
      scanf("%d", &b[i]);

    memset(residual, 0, sizeof residual);

    for(int i = 1; i <= n; i++) {
      residual[0][i] = 1;
      for(int j = 1; j <= m; j++) {
        if((a[i] == 0 && b[j] == 0) || (a[i] && (b[j] % a[i]) == 0)) {
          residual[i][n+j] = 1;
        }
      }
    }

    for(int i = 1; i <= m; i++) {
      residual[n+i][n+m+1] = 1;
    }
    source = 0;
    sink = n+m+1;
    N = n+m+2;

    int card = max_flow();
    printf("Case %d: %d\n", case_id, card);
  }

  return 0;
}

