#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int a[N];

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, d;
  cin >> n >> d;

  for (int i = 0; i < n; i++)
    cin >> a[i];

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++)
      ans += abs(a[i]-a[j]) <= d;
  }

  cout << (2 * ans) << '\n';

  return 0;
}
