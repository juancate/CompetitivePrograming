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

int n, m, x[210], y[210], owner[210];
double dist[110];
bool used[210];
vector<int> g[210], ans[110];

inline
int sqr(int x) {
  return x*x;
}

int khun(int left) {
  if(used[left]) return 0;
  used[left] = true;
  for(int j = 0; j < g[left].size(); j++) {
    int right = g[left][j];
    if(owner[right] == -1 || khun(owner[right])) {
      owner[right] = left;
      return 1;
    }
  }
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);

  while(t--) {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
      scanf("%d%d", &x[i], &y[i]);
    for(int i = n; i < n+m; i++)
      scanf("%d%d", &x[i], &y[i]);

    for(int i = 0; i < n-1; i++) {
      dist[i] = 2 * sqrt(sqr(x[i] - x[i+1]) + sqr(y[i] - y[i+1]));
      for(int j = n; j < n+m; j++) {
        double curr_dist = sqrt(sqr(x[i] - x[j]) + sqr(y[i] - y[j]));
        curr_dist += sqrt(sqr(x[i+1] - x[j]) + sqr(y[i+1] - y[j]));

        if(curr_dist <= dist[i]) {
          g[i].push_back(j);
        }
      }
    }

    int card = 0;
    memset(owner, -1, sizeof owner);
    for(int left = 0; left < n; left++) {
      memset(used, 0, sizeof used);
      card += khun(left);
    }
    for(int i = n, j = 0; i < n+m && j < card; i++) {
      if(owner[i] != -1) {
        ans[owner[i]].push_back(i);
        j++;
      }
    }

    printf("%d\n", card+n);

    for(int i = 0; i < n; i++) {
      if(i) printf(" ");
      printf("%d %d", x[i], y[i]);
      for(int j = 0; j < ans[i].size(); j++)
        printf(" %d %d", x[ans[i][j]], y[ans[i][j]]);
    }

    printf("\n");
    if(t) printf("\n");

    for(int i = 0; i < n; i++) {
      ans[i].clear();
      g[i].clear();
    }
    for(int i = n; i < n+m; i++)
      g[i].clear();
  }

  return 0;
}

