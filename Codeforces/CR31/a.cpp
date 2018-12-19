#include <bits/stdc++.h>

using namespace std;

int n, a[111];

void solve() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) if (j != i) {
      for (int k = 0; k < n; k++) if (k != i && k != j) {
        if (a[i] == a[j]+a[k]) {
          cout << i+1 << ' ' << j+1 << ' ' << k+1 << '\n';
          return;
        }
      }
    }
  }
  cout << -1 << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  solve();

  return 0;
}
