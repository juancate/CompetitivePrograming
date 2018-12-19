#include <bits/stdc++.h>

using namespace std;

const int maxn = 303;

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

    int moves = 0;
    for (int i = 0; i < k; i++) {
      if (b[i] > 0) {
        int t = 0;
        while (i + (1 << t) < n) t++;
        t--;
        moves += b[i];
        b[i+(1<<t)] += b[i];
        b[i] = 0;
      }
    }
    cout << moves << '\n';
  }

  return 0;
}
