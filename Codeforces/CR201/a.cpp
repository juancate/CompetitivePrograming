#include <bits/stdc++.h>

using namespace std;

const int INF = int(1e9);

const int maxn = 111;

int n, a[maxn];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a+n);
  sort(a+1, a+n-1);
  swap(a[n-1], a[0]);

  for (int i = 0; i < n; i++) {
    if (i) cout << ' ';
    cout << a[i];
  }
  cout << '\n';

  return 0;
}
