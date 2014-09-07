#include <bits/stdc++.h>

using namespace std;

int a[110];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, s;
  cin >> n >> s;

  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a+n);

  int sum = 0;
  for (int i = 0; i < n-1; i++)
    sum += a[i];

  if (sum > s) cout << "NO\n";
  else cout << "YES\n";

  return 0;
}

