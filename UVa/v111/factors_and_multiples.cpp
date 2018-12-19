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

int a[maxn], b[maxn], owner[maxn+maxn], visited[maxn+maxn], n, m;
vector<int> g[maxn+maxn];

int khun(int left) {
  if(visited[left]) return 0;
  visited[left] = true;

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

  for(int case_id = 1; case_id <= t; case_id++) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
      scanf("%d", &a[i]);

    scanf("%d", &m);
    for(int i = 0; i < m; i++)
      scanf("%d", &b[i]);

    for(int i = 0; i < n+m; i++)
      g[i].clear();

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if((a[i] == 0 && b[j] == 0) || (a[i] && (b[j] % a[i]) == 0)) {
          g[i].push_back(j+n);
        }
      }
    }

    int card = 0;
    memset(owner, -1, sizeof owner);
    for(int left = 0; left < n; left++) {
      memset(visited, 0, sizeof visited);
      card += khun(left);
    }
    printf("Case %d: %d\n", case_id, card);
  }

  return 0;
}

