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
#include <set>
#include <map>
#include <algorithm>

#define D(x) cerr << #x << " = " << x << endl
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

using namespace std;

int p[2010];
int dist[2010];

int dfs(int u) {
  if(dist[u] != 0 || p[u] < 0)
    return dist[u];

  return dist[u] = 1 + dfs(p[u]);
}

int main() {
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  memset(p, -1, sizeof(p));

  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if(x > 0) {
      x--;
      p[i] = x;
    }
  }

  memset(dist, 0, sizeof(dist));

  int best = -INF;
  for(int i = 0; i < n; i++) {
    if(dist[i] == 0) {
      dfs(i);
      best = max(best, dist[i]);
    }
  }

  cout << best+1 << endl;

  return 0;
}

