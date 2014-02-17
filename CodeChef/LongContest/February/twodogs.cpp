#include <bits/stdc++.h>

using namespace std;

const int INF = int(1e9);

const int N = 1000010;

int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  cin >> n >> k;

  unordered_map<int, int> b;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (b.count(a[i]))
      b[a[i]] = min(b[a[i]], min(i+1, n-i));
    else
      b[a[i]] = min(i+1, n-i);
  }

  int ans = INF;

  for (int i = 0; i < n; i++) {
    int x = a[i];
    int y = k - a[i];

    if (x == y)
      continue;

    if (b.count(y))
      ans = min(ans, max(b[x], b[y]));
  }

  cout << (ans == INF? -1 : ans) << '\n';

  return 0;
}
