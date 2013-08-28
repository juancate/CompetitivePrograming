#include <bits/stdc++.h>

using namespace std;

bool seen[1111];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  memset(seen, 0, sizeof(seen));
  set<int> leaves;
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v;
    seen[u] = seen[v] = 1;
    leaves.insert(u);
    leaves.insert(v);
  }

  int root = -1;
  for (int i = 1; i <= n; i++) {
    if (!seen[i]) {
      if (root == -1) root = i;
      else leaves.insert(i);
    }
  }

  vector<int> childs(leaves.begin(), leaves.end());
  cout << childs.size() << '\n';
  for (int i = 0; i < childs.size(); i++) {
    cout << root << " " << childs[i] << '\n';
  }

  return 0;
}
