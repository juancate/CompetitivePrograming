#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int indegree[1000];
vector<int> g[1000];
vector<int> zeros;

int main() {
  int n, m;

  while(scanf("%d%d", &n, &m)) {
    if(!(n|m)) break;

    for(int i = 0; i < n; i++) {
      indegree[i] = 0;
      g[i].clear();
    }

    for(int i = 0; i < m; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      a--; b--;
      indegree[b]++;
      g[a].push_back(b);
    }

    zeros.clear();

    for(int i = 0; i < n; i++) {
      if(!indegree[i])
        zeros.push_back(i);
    }

    int ans = 1;

    for(int i = 0; i < n; i++) {
      if(zeros.empty()) {
        ans = 0;
        break;
      }
      else if(zeros.size() > 1) {
        ans = 2;
      }

      int curr = zeros.front();
      zeros.erase(zeros.begin());

      for(int j = 0; j < g[curr].size(); j++) {
        int v = g[curr][j];
        indegree[v]--;
        if(!indegree[v])
          zeros.push_back(v);
      }
    }

    printf("%d\n", ans);
  }

  return 0;
}
