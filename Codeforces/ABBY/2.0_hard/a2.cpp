#include <bits/stdc++.h>

using namespace std;

const int maxn = 2002;

int n, a[maxn], b[maxn];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  for (int k = 1; k < n; k++) {
    for (int i = 0; i < n; i++)
      b[i] = a[i];

    long long moves = 0;
    for (int i = 0; i < k; i++) {
      if (b[i] > 0) {
        int t = 1;
        while (i + t < n) t <<= 1;
        t >>= 1;
        if (i == k-1) cerr << "t => " << t << '\n';
        moves += b[i];
        b[i+t] += b[i];
        b[i] = 0;
      }
    }
    cout << moves << '\n';
  }

  return 0;
}
