#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>

#define D(x) cerr << #x << " = " << x << endl
#define INF 10000000
#define ici(a, b, c) make_pair(a, make_pair(b, c))

using namespace std;

typedef pair<char, int> ci;
typedef pair<int, ci> ici;
typedef vector<ici> edges;
typedef vector<edges> graph;
typedef pair<int, int> ii;
typedef priority_queue<ici, vector<ici>, greater<ici> > p_queue;


graph G;
string name, dest, word;
//char name[100], dest[100], word[100];
int M, start, end;

int costoUniforme() {
	int size = G.size();
	p_queue pq;
	map<pair<int, char>, bool> visited;

	pq.push(ici(0, 0, start));

	while(!pq.empty()) {
		ici state = pq.top();
		pq.pop();
		int u = state.second.second;
		char prevch = state.second.first;

		if(visited.find(make_pair(u, prevch)) != visited.end()) continue;
		if(u == end) return state.first;

		visited[make_pair(u, prevch)] = true;

		edges& adj = G[u];
		for(int i = 0; i < adj.size(); i++) {
			int v = adj[i].first;
			char currch = adj[i].second.first;
			if(currch == prevch) continue;
			if(visited.find(make_pair(v, currch)) == visited.end()) {
				pq.push(ici(state.first + adj[i].second.second, currch, v));
			}
		}
	}
	return INF;
}

int dijkstraHeap() {
	int size = G.size();
	vector<int> dist(size, INF);
	vector<int> prev(size, -1);
	map<char, bool> visited[size];

	p_queue pq;
	
	dist[start] = 0;
	pq.push(ici(dist[start], 0, start));

	while(!pq.empty()) {
		ici state = pq.top();
		int u = state.second.second;
		D(u);
		char prevch = state.second.first; // depends on problem
		pq.pop();

		if(visited[u].find(prevch) != visited[u].end()) continue;
		visited[u][prevch] = true;

		edges& adj = G[u];
		for(int i = 0; i < adj.size(); i++) {
			if(adj[i].second.first == prevch) continue; // depends on problem
			int v = adj[i].first;
			D(v);
			int ndist = dist[u] + adj[i].second.second; // dist[u] + dist_between(u, v);
			if(ndist < dist[v]) {
				dist[v] = ndist;
				prev[v] = u;
				pq.push(ici(state.first+adj[i].second.second, adj[i].second.first, v));
			}
//			D(dist[v]);
		}
	}
	return dist[end];
}

int dijkstra() {
	int size = G.size();
	vector<int> dist(size, INF);
	vector<int> prev(size, -1);
	vector<bool> visited(size, false);
	vector<char> fromch(size, -1);
	
	dist[start] = 0;
	fromch[start] = 0;

	for(int i = 0; i < size; i++) {
		int idx = -1;
		for(int j = 0; j < size; j++) if(!visited[j]) {
			if(idx == -1 || dist[idx] > dist[j])
				idx = j;
		}

		visited[idx] = true;
		char pch = fromch[idx];
		edges& adj = G[idx];
		D(pch);
		for(int j = 0; j < size; j++) {
			ici state = adj[j];
			if(pch == state.second.first) continue;
			if(dist[idx]+state.second.second < dist[state.first]) {
				dist[state.first] = dist[idx] + state.second.second;
				prev[state.first] = idx;
				fromch[state.first] = state.second.first;
			}
		}
	}
	return dist[end];
}

int main() {
	while(true) {
		//scanf("%d\n", &M);
		cin >> M;
		if(M == 0) break;
		//scanf("%s %s\n", name, dest);
		cin >> name >> dest;

		map<string, int> index;
		index[name] = start = index.size() - 1;
		index[dest] = end   = index.size() - 1;
		D(G.size());
		G.resize(2);

		for(int i = 0; i < M; i++) {
			//scanf("%s %s %s\n", name, dest, word);
			cin >> name >> dest >> word;
			if(index.find(name) == index.end()) { 
				index[name] = index.size() - 1;
				G.resize(G.size()+1);
			}
			if(index.find(dest) == index.end()) {
				index[dest] = index.size() - 1;
				G.resize(G.size()+1);
			}
			int a = index[name], b = index[dest];
			//D(a); D(b);
			G[a].push_back(ici(b, word[0], word.length()));
			G[b].push_back(ici(a, word[0], word.length()));
			//D(name); D(dest); D(word);
		}
		
		int ans = dijkstraHeap();
		if(ans == INF) puts("impossivel");
		else printf("%d\n", ans);

		G.clear();
	}
}
