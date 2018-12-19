#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int sum[N][3], a[N];

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    memset(sum, 0, sizeof sum);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];

      for (int j = 0; j < 3; j++)
        sum[i][j] += sum[i-1][j];

      if (a[i] < 3)
        sum[i][a[i]]++;
    }

    long long ans = 0;
    for (int j = 1; j <= n; j++) {
      long long curr = j-1;
      curr = curr - sum[j-1][0] - sum[j-1][1];

      if (a[j] < 2)
        curr = 0;
      else if (a[j] == 2)
        curr -= sum[j-1][2];

      ans += curr;
    }

    cout << ans << '\n';
  }

  return 0;
}
