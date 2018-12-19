#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> a;
  int v;
  while (cin >> v)
    a.push_back(v);
  sort(a.begin(), a.end());

  for (int i = 0; i < a.size(); i++) {
    if (i) cout << '+';
    cout << a[i];
  }
  cout << '\n';

  return 0;
}
