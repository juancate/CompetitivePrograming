#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("f.in", "r", stdin);
  freopen("f.out", "w", stdout);
#else
  ios_base::sync_with_stdio(false);
#endif

  int n;
  while(cin >> n) {
    if(!n) break;

    vector<string> g(n);
    for(int i = 0; i < n; i++) {
      cin >> g[i];
    }
    sort(g.begin(), g.end());

    int m = (n >> 1) - 1;

    string ans = "";

    for(int i = 0; i < g[m].size(); i++) {
      ans.push_back(g[m][i]);
      if(g[m] <= ans && ans < g[m+1])
        break;

      if(g[m][i] == 'Z') continue;

      ans[ans.size()-1]++;
      if(g[m] <= ans && ans < g[m+1])
        break;
      ans[ans.size()-1]--;
    }

    cout << ans << endl;
  }

  return 0;
}
