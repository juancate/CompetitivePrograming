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

char g[111][111];
bool seen[111][111];

int main() {
  ios_base::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  for(int i = 0; i < n; i++)
    cin >> g[i];

  memset(seen, 0, sizeof(seen));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(!seen[i][j]) {
        char curr = g[i][j];
        for(int k = 0; k < m; k++) {
          if(k != j) {
            if(g[i][k] == curr)
              seen[i][k] = seen[i][j] = true;
          }
        }

        for(int k = 0; k < n; k++) {
          if(k != i) {
            if(g[k][j] == curr)
              seen[k][j] = seen[i][j] = true;
          }
        }
      }
    }
  }

  string ans;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++)
      if(!seen[i][j])
        ans.push_back(g[i][j]);
  }

  cout << ans << endl;

  return 0;
}

