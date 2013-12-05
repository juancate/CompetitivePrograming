#include <bits/stdc++.h>

#define foreach(it,v) \
  for (__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)

using namespace std;

int n, m, a[3010];

bool solve() {
  if (a[0] == 1 || a[m-1] == n)
    return false;

  for (int i = 2; i < m; i++)
    if (a[i] == a[i-1]+1 && a[i] == a[i-2]+2)
      return false;

  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < m; i++)
    cin >> a[i];
  sort(a, a+m);

  cout << (solve()? "YES" : "NO") << '\n';

  return 0;
}

