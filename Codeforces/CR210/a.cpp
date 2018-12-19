#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  cin >> n >> k;

  if (k == n) {
    cout << -1 << '\n';
  }
  else {
    for (int i = 0; i < n; i++)
      a[i] = i+1;
    for (int i = 1, t = k; i < n; i++) {
      if (t > 0)
        t--;
      else
        swap(a[i], a[(i+1) % n]);
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (__gcd(a[i], i+1) > 1) cnt++;
      cout << a[i] << ' ';
    }
    assert(cnt == k);
    cout << '\n';
  }

  return 0;
}
