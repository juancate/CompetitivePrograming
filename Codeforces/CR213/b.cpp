#include <bits/stdc++.h>

#define foreach(it,v) \
  for (__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)

using namespace std;

const int N = 100010;

int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> a[i];

  int ans = min(2, n);
  int l = 0, r = 0;
  for (int i = l+2; i < n; i++) {
    l = i-2;
    while (i < n && a[i] == (a[i-1]+a[i-2]))
      i++;
    r = i-1;

    ans = max(ans, r-l+1);
  }

  cout << ans << '\n';

  return 0;
}

