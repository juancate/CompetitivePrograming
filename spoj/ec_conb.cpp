#include <bits/stdc++.h>

using namespace std;

int solve(int x) {
  string t;
  while (x) {
    t.push_back('0' + (x & 1));
    x >>= 1;
  }
  return strtol(t.c_str(), NULL, 2);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  for (int i = 0, v; i < n; i++) {
    cin >> v;
    int ans = (v & 1)? v : solve(v);
    cout << ans << '\n';
  }

  return 0;
}
