#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    int n, best, curr;
    cin >> n >> best;

    for (int i = 1; i < n; i++) {
      cin >> curr;
      best = max(best, curr + i);
    }

    cout << best << '\n';
  }

  return 0;
}
