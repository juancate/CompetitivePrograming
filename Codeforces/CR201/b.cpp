#include <bits/stdc++.h>

using namespace std;

const int maxn = int(1e5);

int a[maxn];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int ans = 0;
  for (int i = 0; i < n; i++)
    if (a[i] == i) ans++;
  bool found = false;
  for (int i = 0; i < n; i++)
    if (a[i] != i) {
      if (a[a[i]] == i) {
        found = true;
        break;
      }
    }
  if (found) ans += 2;
  else if (ans < n) ans++;

  cout << ans << '\n';

  return 0;
}
