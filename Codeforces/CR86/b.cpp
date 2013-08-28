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

bool g[20][20];
map<string,int> contestants;
string names[20];

int main() {
  ios_base::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  for(int i = 0; i < n; i++) {
    string s;
    cin >> s;
    contestants[s] = i;
    names[i] = s;
  }

  for(int i = 0; i < m; i++) {
    string a, b;
    cin >> a >> b;
    int u = contestants[a];
    int v = contestants[b];
    g[u][v] = g[v][u] = true;
  }

  int best = 0, best_team = 0;

  for(int subset = 0; subset < (1<<n); subset++) {
    bool valid = true;

    for(int j = 0; j < n; j++) {
      if((subset & (1 << j)) != 0) {
        for(int k = 0; k < n; k++) {
          if(g[j][k] && (subset & (1 << k)) != 0) {
            valid = false;
            break;
          }
        }
        if(!valid)
          break;
      }
    }

    if(!valid)
      continue;
    int curr = __builtin_popcount(subset);
    if(curr > best) {
      best = curr;
      best_team = subset;
    }
  }

  cout << best << endl;

  vector<string> ans;
  for(int i = 0; i < n; i++) {
    if((best_team & (1 << i)) != 0) {
      ans.push_back(names[i]);
    }
  }

  sort(ans.begin(), ans.end());
  for(int i = 0; i < ans.size(); i++)
    cout << ans[i] << endl;

  return 0;
}

