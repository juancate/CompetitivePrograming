#include <bits/stdc++.h>

using namespace std;

const int maxn = int(1e5)+10;

int n, m, a[maxn];

int dist(int i, int j) {
  if (j < i)
    return (n-i)+j;
  return j-i;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  for (int i = 0; i < m; i++)
    cin >> a[i];

  long long ans = 0;
  int prev = 1;
  for (int i = 0; i < m; i++) {
    ans += dist(prev, a[i]);
    prev = a[i];
  }
  cout << ans << '\n';

  return 0;
}
