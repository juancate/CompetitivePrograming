#include <bits/stdc++.h>

#define foreach(it,v) \
  for (__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)

using namespace std;

int a[1111], b[1111], ca[1111], cb[1111];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long long c1, c2, c3, c4, n, m;
  cin >> c1 >> c2 >> c3 >> c4 >> n >> m;

  long long suma = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ca[i] = min(c1 * a[i], c2);
    suma += ca[i];
  }
  suma = min(suma, c3);

  long long sumb = 0;
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    cb[i] = min(c1 * b[i], c2);
    sumb += cb[i];
  }
  sumb = min(sumb, c3);

  cout << min(suma + sumb, c4) << '\n';

  return 0;
}

