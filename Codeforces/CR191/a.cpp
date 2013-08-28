#include <bits/stdc++.h>

using namespace std;

int a[111], sum[111];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  memset(sum,0,sizeof(sum));
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i == 0) sum[i] = (a[i] == 0);
    else sum[i] = sum[i-1] + (a[i] == 0);
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      int curr = sum[j];
      if (i > 0) curr -= sum[i-1];

      for (int k = 0; k < i; k++)
        curr += a[k];
      for (int k = j+1; k < n; k++)
        curr += a[k];
      ans = max(ans, curr);
    }
  }
  cout << ans << '\n';

  return 0;
}
