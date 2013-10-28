#include <bits/stdc++.h>

using namespace std;

long long ans[111];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ans[1] = 1;
  for (int i = 2; i < 101; i++)
    ans[i] = i*i + ans[i-1];

  int n;
  while (cin >> n) {
    if (n == 0)
      break;
    cout << ans[n] << '\n';
  }

  return 0;
}
