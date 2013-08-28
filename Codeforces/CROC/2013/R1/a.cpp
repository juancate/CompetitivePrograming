#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;

  long long q = 0, best = 0;
  int last = 0, time = 0;
  for (int i = 0; i < n; i++) {
    int ti, ci;
    cin >> ti >> ci;

    q = max(0LL, q - (ti - last));
    q += ci;
    best = max(best, q);

    last = ti;
  }
  time = last + q;
  cout << time << ' ' << best << '\n';

  return 0;
}
