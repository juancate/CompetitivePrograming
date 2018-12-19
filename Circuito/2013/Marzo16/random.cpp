#include <iostream>
#include <vector>

using namespace std;

vector<int> g[1<<11];

int main() {
  ios_base::sync_with_stdio(false);

  int n, k, e;
  while(cin >> k >> n >> e) {
    if(!(n|k|e)) break;

    int N = 1<<n;
    for(int i = 0; i < N; i++) {
      g[i].clear();
    }

    for(int i = 0; i < e; i++) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }

    vector<double> p;
    bool ok = true;
    for(int l = 0; l < k; l++) {
      vector<double> curr_p(N);

      if(l == 0) {
        for(int i = 0; i < N; i++)
          curr_p[i] = 1. / N;
      }
      else {
        for(int i = 0; i < N; i++) {
          for(int j = 0; j < g[i].size(); j++) {
            curr_p[g[i][j]] += p[i] / g[i].size();
          }
        }
      }

      vector<double> f(n);
      for(int i = 0; i < N; i++) {
        for(int j = 0; j < n; j++) {
          if((i & (1 << j)) > 0) {
            f[j] += curr_p[i];
          }
        }
      }
      for(int i = 0; i < n; i++) {
        if(f[i] <= 0.25 || 0.75 <= f[i]) {
          ok = false;
          break;
        }
      }

      p = curr_p;
      if(!ok) break;
    }
    cout << (ok? "Yes" : "No") << endl;
  }

  return 0;
}
