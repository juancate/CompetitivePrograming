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

#define D(x) cerr << #x << " = " << x << endl
#define REP(i,n) for(int i=0; i<n; i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)

#define INF 1<<30
#define EPS 1e-13

// 10147 - Highways
// Algorithm: Kruskal MST

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> Graph;
typedef priority_queue<iii, vector<iii>, greater<iii> > p_queue;

//int graph[800][800];
bool visited[800], connected[800][800];
int parent[800], points[800][2];

vi pertenece, rank, size;
p_queue edges;
Graph tree;

int t, n, m;

int distanc(int x, int y) {
  return ((x*x) + (y*y));
}

void init() {
	pertenece.resize(n);
	rank.resize(n, 0);
	size.resize(n, 1);
	for(int i = 0; i < n; i++) {
		pertenece[i] = i;
	}
}

int find(int x) {
	if(x == pertenece[x])
		return x;
	return pertenece[x] = find(pertenece[x]);
}

void unionS(int x, int y) {
	int xp = find(x), yp = find(y);
	if(xp == yp)
		return;
	if(rank[xp] < rank[yp]) {
		pertenece[xp] = yp;
		size[yp] += size[xp];
	}
	else {
		pertenece[yp] = xp;
		size[xp] += size[yp];
		if(rank[xp] == rank[yp])
			rank[xp]++;
	}
}

int kruskal() {
	init();
	int edg = 0;
	int ans = 0;
  
  while(edg < n-1) {
		iii minEdge = edges.top(); edges.pop();
    int from = minEdge.second.first;
    int to = minEdge.second.second;
    
		int a = find(from);
		int b = find(to);
		
		if(a != b) { // no están ya en el mismo conjunto
			ans += minEdge.first; // Agrego la arista

			unionS(a, b);
			edg++;
      
      tree[from].push_back(to);
      tree[to].push_back(from);
		}
	}
  return ans;
}

void dfs(int node, int p) { // Construir arbol
  parent[node] = p;
  visited[node] = true;
  FOREACH(it, tree[node]) if(!visited[*it])
    dfs(*it, node);
}

int main() {
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);

    REP(i, n) scanf("%d %d", &points[i][0], &points[i][1]); // x, y
    
    memset(visited, false, sizeof(visited));
    memset(connected, false, sizeof(connected));
    memset(parent, -1, sizeof(parent));
    tree.resize(n);
      
    scanf("%d", &m);

    REP(i, m) {
      int a, b;
      scanf("%d %d", &a, &b);
      //graph[a-1][b-1] = graph[b-1][a-1] = 0;
      connected[a-1][b-1] = connected[b-1][a-1] = true;
      edges.push(iii(0, ii(a-1, b-1)));
    }

    REP(i, n) for(int j = i; j < n; j++) if(i != j and !connected[i][j]){
      int d = distanc((points[i][0] - points[j][0]), (points[i][1] - points[j][1]));
      //graph[i][j] = graph[j][i] = d;
      edges.push(iii(d, ii(i, j)));
    }
    
    kruskal();
    dfs(0, -1);

    bool full = true;
    REP(i, n) if(parent[i] != -1 and !connected[i][parent[i]]) {
      printf("%d %d\n", (i+1), (parent[i]+1));
      full = false;
    }
    if(full) puts("No new highways need");

    if(t) puts("");

    tree.clear();
    while(!edges.empty()) edges.pop();
  }
}

