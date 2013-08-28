#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  long long n, k;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    if (k > 0)
      cout << n/k << ' ' << n%k << '\n';
    else
      cout << 0 << ' ' << n << '\n';
  }
  return 0;
}
