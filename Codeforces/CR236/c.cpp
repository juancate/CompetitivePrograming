#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    int n, p;
    cin >> n >> p;

    int edges = 2*n + p;
    int u = 1;

    vector< pair<int,int> > ans;
    while (edges > 0) {
      for (int v = u+1; v <= n; v++) {
        if (edges == 0)
          break;

        edges--;
        ans.push_back(make_pair(u, v));
      }
      u++;
    }

    for (pair<int,int> curr : ans)
      cout << curr.first << ' ' << curr.second << '\n';
  }

  return 0;
}
