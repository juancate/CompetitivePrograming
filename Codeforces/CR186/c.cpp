#include <bits/stdc++.h>

using namespace std;

int a[2000010];

long long getn(int m) {
  return (long long)round(log(m) / log(4));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int m;
  cin >> m;
  for (int i = 0; i < m; i++)
    cin >> a[i];
  sort(a, a+m);

  long long n = getn(m);
  int last = m-1, limit = 3;
  long long ans = (n + 1) * a[last--];

  for (long long i = n; i > 0; i--) {
    long long curr = 0;
    for (int j = 0; j < limit; j++)
      curr += a[last--];
    limit *= 4;
    ans = ans + (curr * i);
  }
  cout << ans << '\n';

  return 0;
}
