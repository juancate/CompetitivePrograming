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

// 908 - Re-connecting Computer Sites
// Algorithm: MST - Kruskal

#define INF 1<<30

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef priority_queue<iii, vector<iii>, greater<iii> > p_queue;

int n, m, k;

vi pertenece, rank, size;
p_queue edges;

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
	int a, b;
	int edg = 0;
	int ans = 0;
	while(edg < n-1) {
		iii minEdge = edges.top(); edges.pop();

		int a = find(minEdge.second.first);
		int b = find(minEdge.second.second);
		
		if(a != b) { // no están ya en el mismo conjunto
			ans += minEdge.first; // Agrego la arista
			unionS(a, b);
			edg++;
		}
	}
	return ans;
}

int main() {
  scanf("%d\n", &n);
	while(true) {
    int a, b, cost, t = 0;
		REP(i, n-1) {
      scanf("%d %d %d\n", &a, &b, &cost);
      t += cost;
    }
    scanf("%d\n", &k);
    REP(i, k) {
      scanf("%d %d %d\n", &a, &b, &cost);
      edges.push(iii(cost, ii(a-1, b-1)));
    }
    scanf("%d\n", &m);
		REP(i, m){
      scanf("%d %d %d\n", &a, &b, &cost);
      edges.push(iii(cost, ii(a-1, b-1)));
		}
		int ans = kruskal();
		printf("%d\n%d\n", t, ans);

		while(!edges.empty()) edges.pop();
    
    if(scanf("%d\n", &n) == 1) printf("\n");
    else break;
	}
}


