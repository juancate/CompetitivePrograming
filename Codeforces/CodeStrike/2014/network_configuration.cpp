#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  cin >> n >> k;

  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  sort(v.rbegin(), v.rend());
  cout << v[k-1] << '\n';

  return 0;
}
