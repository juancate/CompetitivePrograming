#include <bits/stdc++.h>

using namespace std;

long long C[33][33];

void calc_comb() {
  for (int i = 0; i < 31; i++)
    for (int j = 0; j <= i; j++)
      if (j == 0 || j == i) C[i][j] = 1;
      else C[i][j] = C[i-1][j-1] + C[i-1][j];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  calc_comb();

  int n, m, t;
  cin >> n >> m >> t;

  long long ans = 0;

  for (int boys = 4; boys <= n; boys++) {
    if (boys > t)
      break;
    int girls = t - boys;
    if (girls >= 1 && girls <= m)
      ans += C[n][boys] * C[m][girls];
  }

  cout << ans << '\n';

  return 0;
}
