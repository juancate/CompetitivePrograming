#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

#define D(x) cerr << #x << " = " << x << endl
#define INF 1000000000

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> edges;
typedef vector<edges> graph;
typedef priority_queue<ii, edges, greater<ii> > p_queue;

int N, n, m, s, t;
graph G;

int dijkstra() {
	int dist[n];
	bool visited[n];
	p_queue pq;
	memset(visited, false, sizeof(visited));
	fill(dist, dist+n, INF);
	
	dist[s] = 0;
	pq.push(ii(0, s)); // dist, node

	while(!pq.empty()) {
		ii state = pq.top();
		pq.pop();

		int u = state.second;
		int cost = state.first;

		if(visited[u]) continue;
		visited[u] = true;

		edges& adj = G[u];
		for(int i = 0; i < adj.size(); i++) {
			int v = adj[i].first;
			int c = adj[i].second;
			if(dist[u] + c < dist[v]) {
				dist[v] = dist[u] + c;
				pq.push(ii(cost + c, v));
			}
		}
	}
	return dist[t];
}

int main() {
	scanf("%d", &N);
	for(int id = 1; id <= N; id++) {
		scanf("%d %d %d %d", &n, &m, &s, &t);

		G.resize(n);
		for(int i = 0; i < m; i++) {
			int x, y, w;
			scanf("%d %d %d", &x, &y, &w);
			G[x].push_back(ii(y, w));
			G[y].push_back(ii(x, w));
		}

		int ans = dijkstra();
		
		if(ans == INF) printf("Case #%d: unreachable\n", id);
		else printf("Case #%d: %d\n", id, ans);

		G.clear();
	}
}
