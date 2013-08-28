#include <bits/stdc++.h>

using namespace std;

const int maxn = 4010;

int a[maxn], b[maxn], c[maxn], d[maxn];
int n, cd[maxn*maxn];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i] >> b[i] >> c[i] >> d[i];

  int m = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cd[m++] = c[i]+d[j];
  sort(cd, cd+m);

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int inv = -(a[i]+b[j]);
      int k = lower_bound(cd, cd+m, inv) - cd;
      int l = upper_bound(cd, cd+m, inv) - cd;

      if (cd[k] == inv) {
        if (l == m || cd[l] != inv)
          l--;
        ans += l-k+1;
      }
    }
  }
  cout << ans << '\n';

  return 0;
}
