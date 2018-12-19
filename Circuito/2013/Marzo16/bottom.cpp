#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

#define foreach(it,v) for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); it++)

using namespace std;

vector<int> g[50010], scc[50010], dfs_num, dfs_low, S, visited;
int dfsNumberCounter, numSCC, in_scc[50010];

void tarjanSCC(int u) {
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
  S.push_back(u);
  visited[u] = 1;
  for(int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    if(dfs_num[v] == -1) {
      tarjanSCC(v);
    }
    if(visited[v]) {
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
  }
  if(dfs_low[u] == dfs_num[u]) {
    ++numSCC;
    while(true) {
      int v = S.back();
      S.pop_back();
      visited[v] = 0;
      scc[numSCC-1].push_back(v);
      in_scc[v] = numSCC;
      if(u == v) break;
    }
  }
}

int main() {

//#ifdef LOCAL
//  freopen("bottom.in", "r", stdin);
//  freopen("bottom.out", "w", stdout);
//#else
  ios_base::sync_with_stdio(false);
//#endif

  int v, e;
  while(cin >> v) {
    if(!v) break;
    cin >> e;

    for(int i = 0; i < e; i++) {
      int from, to;
      cin >> from >> to;
      g[from].push_back(to);
    }
    
    vector<int> ans;
    dfs_num.assign(v+1, -1); dfs_low.assign(v+1, 0); visited.assign(v+1, 0);
    dfsNumberCounter = numSCC = 0;
    for(int i = 1; i <= v; i++) {
      if(dfs_num[i] == -1) {
        tarjanSCC(i);
      }
    }
    
    for(int i = 0; i < numSCC; i++) {
      bool sink = true;
      for(int j = 0; j < scc[i].size(); j++) {
        int u = scc[i][j];
        for(int k = 0; k < g[u].size(); k++) {
          int v = g[u][k];
          if(in_scc[u] != in_scc[v]) {
            sink = false;
            break;
          }
        }
        if(!sink) break;
      }
      if(sink) {
        for(int j = 0; j < scc[i].size(); j++) {
          ans.push_back(scc[i][j]);
        }
      }
    }
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++) {
      if(i) cout << " ";
      cout << ans[i];
    }
    cout << endl;
    for(int i = 1; i <= v; i++) {
      g[i].clear();
    }
    for(int i = 0; i < numSCC; i++) {
      scc[i].clear();
    }
  }

  return 0;
}
