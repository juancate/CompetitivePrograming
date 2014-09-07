#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int n, x[N], c[N];

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> n) {
    set<int> x_set;
    for (int i = 0; i < n; i++) {
      cin >> x[i] >> c[i];
      x_set.insert(x[i]);
    }

    vector<int> cities(x_set.begin(), x_set.end());
    int best = -int(1e9), ans = -1;
    for (int i = 0; i < n; i++) {
      int s = upper_bound(cities.begin(), cities.end(), x[i]) - cities.begin();
      int e = upper_bound(cities.begin(), cities.end(), x[i]+c[i]) - cities.begin();

      if (e-s > best) {
        best = e-s;
        ans = i;
      }
    }

    cout << x[ans] << ' ' << best << '\n';
  }

  return 0;
}
