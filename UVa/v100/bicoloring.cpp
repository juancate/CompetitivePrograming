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

// 10004 - Bicoloring
// Algorithm: DFS, Bipartite graph

#define MAXN 200

using namespace std;

typedef vector<int> vi;
typedef vector<vi> Graph;

int n, l, a, b;
Graph g;
int colors[MAXN+10];
bool visited[MAXN+10];

bool dfs(int node, int color) {
  colors[node] = color;
  visited[node] = true;
  FOREACH(it, g[node]) {
    if(!visited[*it]) dfs(*it, (color == 1)? 0 : 1);
    else if(colors[*it] == color) return false;
  }
  return true;
}

int main() {
  while(true) {
    scanf("%d", &n);

    if(n == 0) break;

    g.clear();
    g.resize(n);
    memset(colors, -1, sizeof(colors));
    memset(visited, false, sizeof(visited));

    scanf("%d", &l);
    REP(i, l) {
      scanf("%d %d", &a, &b);
      g[a].push_back(b);
      g[b].push_back(a);
    }

    puts(dfs(0,0)? "BICOLORABLE." : "NOT BICOLORABLE.");
  }
}

