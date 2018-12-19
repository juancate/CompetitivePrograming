#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>
#include <numeric>

#define D(x) cerr << #x << " = " << x << endl
#define INF 10000000

using namespace std;

typedef pair<int, int> ii;
typedef priority_queue<ii, vector<ii>, greater<ii> > p_queue;

int graph[100][100];
int n;
char line[1000];

int dijkstra() {
	int dist[n], prev[n];
	bool visited[n];
	p_queue pq;

	memset(visited, false, sizeof(visited));
	fill(dist, dist+n, INF);
	fill(prev, prev+n, -1);

	dist[0] = 0;
	pq.push(ii(0, 0));

	while(!pq.empty()) {
		ii state = pq.top();
		pq.pop();
		int u = state.second;

		if(visited[u]) continue;
		visited[u] = true;

		for(int j = 0; j < n; j++) {
			if(graph[u][j] != 0 && graph[u][j] + dist[u] < dist[j]) {
				dist[j] = graph[u][j] + dist[u];
				prev[j] = u;
				pq.push(ii(state.first + graph[u][j], j));
			}
		}
	}
	int maxval = -1;
	for(int i = 1; i < n; i++) maxval = max(maxval, dist[i]);
	return maxval;
}

int main() {
	while(scanf("%d\n", &n) == 1) {
		memset(graph, 0, sizeof(graph));
		for(int i = 1; i < n; i++) {
			fgets(line, sizeof(line), stdin);
			int k = 0, j = 0;
			while(k < strlen(line)-1) {
				while(!isdigit(line[k]) && line[k] != 'x') k++;
				if(line[k] == 'x') {
					j++; k++;
					continue;
				}
				int v = 0;
				int m = k;
				while(isdigit(line[m])) {
					v *= 10;
					v += line[m] - '0';
					m++;
				}
				graph[i][j] = graph[j][i] = v;
				if(m != k) k = m-1;
				k++;
				j++;
			}
		}
		printf("%d\n", dijkstra());
	}
}
