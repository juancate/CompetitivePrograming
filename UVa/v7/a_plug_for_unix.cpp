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

const int maxn = 555;

int n, m, k, devices[111], residual[maxn][maxn];
map<string, int> c;
char _s[100], _d[100];

int N, source, sink, parent[maxn];
bool used[maxn];

int augmenting_path() {
  int where, path_capacity;

  where = sink;
  path_capacity = INF;

  while(parent[where] != -1) {
    int prev = parent[where];
    path_capacity = min(path_capacity, residual[prev][where]);
    where = prev;
  }

  if(path_capacity == INF)
    return 0;

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

  while(t--) {
    c.clear();

    scanf("%d", &n);
    vector<int> v;
    for(int i = 1; i <= n; i++) {
      scanf("%s", _s);
      c[_s] = i;
      v.push_back(i);
    }

    scanf("%d", &m);
    for(int i = 1; i <= m; i++) {
      scanf("%s%s", _s, _d);
      if(!c.count(_d)) {
        c[_d] = c.size();
      }
      devices[i] = m + c[_d];
    }

    memset(residual, 0, sizeof residual);
    scanf("%d", &k);
    for(int i = 1; i <= k; i++) {
      scanf("%s%s", _s, _d);

      if(!c.count(_s)) c[_s] = c.size();
      if(!c.count(_d)) c[_d] = c.size();

      residual[m+c[_s]][m+c[_d]] = INF;
    }

    source = 0;
    sink = m + c.size() + 1;
    N = m + c.size() + 2;

    for(int i = 1; i <= m; i++)
      residual[i][devices[i]] = 1;
    for(int i = 1; i <= m; i++)
      residual[source][i] = 1;
    for(int i = 0; i < n; i++)
      residual[v[i]+m][sink] = 1;

    int mf = max_flow();
    printf("%d\n", m-mf);
    if(t) printf("\n");
  }

  return 0;
}

