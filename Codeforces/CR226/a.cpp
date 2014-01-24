#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, c;
  cin >> n >> c;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int best = 0;
  for (int i = 1; i < n; i++)
    best = max(best, a[i-1]-a[i]-c);
  cout << best << '\n';

  return 0;
}
