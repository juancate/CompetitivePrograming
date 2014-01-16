#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;

long long n;
int a[maxn];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int tc;
  cin >> tc;

  while (tc--) {
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> a[i];

    long long ans = (n * (n - 1)) >> 1;
    cout << ans << '\n';
  }

  return 0;
}
