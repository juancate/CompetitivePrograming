#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;
const int maxn = 1010;

int n, x[maxn], y[maxn];
long long dist[maxn][maxn];

inline long long sqr(long long x) {
  return x*x;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> n) {
    if (n == 0)
      break;

    for (int i = 0; i < n; i++) {
      cin >> x[i] >> y[i];
      dist[i][i] = 0;
      for (int j = 0; j < i; j++) {
        dist[i][j] = sqr(x[i]-x[j]) + sqr(y[i]-y[j]);
        dist[j][i] = dist[i][j];
      }
    }

    for (int i = 0; i < n; i++)
      sort(dist[i], dist[i]+n);

    long long ans = 0;
    for (int i = 0; i < n; i++) {
      double curr = dist[i][1];
      long long cnt = 1;
      for (int j = 2; j < n; j++) {
        if (curr == dist[i][j])
          cnt++;
        else {
          ans += cnt * (cnt-1) / 2;
          curr = dist[i][j];
          cnt = 1;
        }
      }
      ans += cnt * (cnt-1) / 2;
    }
    cout << ans << '\n';
  }
  return 0;
}
