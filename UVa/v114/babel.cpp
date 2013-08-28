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
int M, start, end;

int costoUniforme() {
	int size = G.size();
	p_queue pq;
	map<char, bool> visited[size];

	pq.push(ici(0, 0, start));

	while(!pq.empty()) {
		ici state = pq.top();
		pq.pop();
		int u = state.second.second;
		char prevch = state.second.first;

		if(visited[u].find(prevch) != visited[u].end()) continue;
		if(u == end) return state.first;

		visited[u][prevch] = true;

		edges& adj = G[u];
		for(int i = 0; i < adj.size(); i++) {
			int v = adj[i].first;
			char currch = adj[i].second.first;
			if(currch == prevch) continue;
			if(visited[v].find(currch) == visited[v].end()) {
				pq.push(ici(state.first + adj[i].second.second, currch, v));
			}
		}
	}
	return INF;
}

int main() {
	while(true) {
		cin >> M;
		if(M == 0) break;
		cin >> name >> dest;

		map<string, int> index;
		index[name] = start = index.size() - 1;
		index[dest] = end   = index.size() - 1;

		G.resize(2);

		for(int i = 0; i < M; i++) {
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
			G[a].push_back(ici(b, word[0], word.length()));
			G[b].push_back(ici(a, word[0], word.length()));
		}

		int ans = costoUniforme();
		if(ans == INF) puts("impossivel");
		else printf("%d\n", ans);

		G.clear();
	}
}
