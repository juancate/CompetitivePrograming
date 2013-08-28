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

typedef vector<int> Edges;
typedef vector<Edges> Graph;

const int MAXN = 50000;

int T, N;
Graph g;
bool visited[MAXN + 10];

int dfs(int i) {
  stack<int> tree;
  tree.push(i);
  while(!tree.empty()) {
    
  }
}

int main() {
  scanf("%d", &T);
  REP(id,T) {
    scanf("%d", &N);
    g.clear();
    g.resize(N);
    memset(visited, false, sizeof(visited));

    REP(i,N) {
      int u, v;
      scanf("%d %d", &u, &v);
      g[--u].push_back(--v);
    }
    
    int answer = -1, maxval = -1;
    REP(i, N) {
      memset(visited, false, sizeof(visited));
      int val = dfs(i);
      if(val > maxval) {
        D(i);
        maxval = val;
        answer = i;
      }
    }

    printf("Case %d: %d\n", (id+1), (answer+1));
  }
}

