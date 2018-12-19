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

int owner[210];
bool used[210];
vector<int> g[210];

int khun(int left) {
  if(used[left]) return 0;
  used[left] = true;
  for(int i = 0; i < g[left].size(); i++) {
    int right = g[left][i];
    if(owner[right] == -1 || khun(owner[right])) {
      owner[right] = left;
      return 1;
    }
  }
  return 0;
}

int main() {
  int n, m, k;
  while(scanf("%d%d%d", &n, &m, &k)) {
    if(!n) break;
    for(int i = 0; i < n+m; i++)
      g[i].clear();
    while(k--) {
      int i, x, y;
      scanf("%d%d%d", &i, &x, &y);
      g[x].push_back(y);
    }

    int card = 0;
    memset(owner, -1, sizeof owner);
    for(int left = 1; left < n; left++) {
      memset(used, 0, sizeof used);
      card += khun(left);
    }
    printf("%d\n", card);
  }
  return 0;
}

