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

const int maxn = 100010;
const int mod = INF + 7;

vector<int> g[maxn];
bool used[maxn];

int dfs(int u) {
  used[u] = true;
  int sz = 1;

  for(int i = 0; i < g[u].size(); i++)
    if(!used[g[u][i]])
      sz += dfs(g[u][i]);

  return sz;
}

int main() {
  int t, n, m;
  scanf("%d", &t);

  while(t--) {
    scanf("%d%d", &n, &m);

    for(int i = 0; i < n; i++)
      g[i].clear();
    memset(used, 0, n*sizeof(bool));
    for(int i = 0; i < m; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      a--; b--;
      g[a].push_back(b);
      g[b].push_back(a);
    }

    int scapes = 0;
    int64 capitans = 1;

    for(int i = 0; i < n; i++) {
      if(!used[i]) {
        scapes++;
        capitans = (capitans * dfs(i)) % mod;
      }
    }
    printf("%d %lld\n", scapes, capitans);
  }

  return 0;
}

