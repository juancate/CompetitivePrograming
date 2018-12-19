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

int g[111][111], e[111];

int main() {
  ios_base::sync_with_stdio(false);
  int n, m;

  cin >> n >> m;

  for(int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    g[a][b] = g[b][a] = 1;
    e[a]++; e[b]++;
  }

  int ans = 0;
  while(true) {
    bool kicked = false;
    vector<int> dec;

    for(int u = 1; u <= n; u++) {
      if(e[u] == 1) {
        kicked = true;
        for(int v = 1; v <= n; v++) {
          if(g[u][v]) {
            g[u][v] = g[v][u] = 0;
            dec.push_back(v);
            break;
          }
        }
        e[u]--;
      }
    }

    if(kicked) {
      ans++;
      for(int i = 0; i < dec.size(); i++) {
        e[dec[i]]--;
      }
    }

    if(!kicked) break;
  }

  cout << ans << endl;

  return 0;
}

