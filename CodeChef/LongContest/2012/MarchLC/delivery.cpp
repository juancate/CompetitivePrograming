#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
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

#define D(x) cerr << #x << " = " << x << endl;
#define REP(i,n) for(int i=0; i<n; i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)

#define INF 1<<30
#define EPS 1e-13

using namespace std;

const int MAXN = 100 + 10;

int N, M;
int pset[MAXN], rank[MAXN], size[MAXN];

void init() {
  REP(i, N) pset[i] = i, rank[i] = 0, size[i] = 1;
}

int find(int x) {
  if(pset[x] == x) return x;
  return pset[x] = find(pset[x]);
}

void unionSet(int x, int y) {
  int xp = find(x), yp = find(y);
  if(x == y) return;
  if(rank[xp] < rank[yp]) {
    pset[xp] = yp;
    size[yp] += size[xp];
  } else {
    pset[yp] = xp;
    size[xp] += size[yp];
    if(rank[xp] == rank[yp])
      rank[xp]++;
  }
}
// other form, mark components with dfs if they are in the same component then YO else NO
int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    scanf("%d %d", &N, &M);
    init();
    REP(i, M) {
      int A, B;
      scanf("%d %d", &A, &B);
      if(A != B) unionSet(A, B);
    }
    int Q, X, Y;
    scanf("%d", &Q);
    REP(i, Q) {
      scanf("%d %d", &X, &Y);
      if(find(X) == find(Y)) puts("YO");
      else puts("NO");
    }
  }
}

