#include <bits/stdc++.h>

using namespace std;

int n;
set<int> s;

void dfs(string x) {
  int curr = atoi(x.c_str());
  if (curr < 1 || curr > n)
    return;

  if (s.count(curr))
    return;

  s.insert(curr);
  dfs(x + "0");
  dfs(x + "1");
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;

  dfs("1");
  cout << s.size() << '\n';

  return 0;
}
