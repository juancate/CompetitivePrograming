#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int a[N];

int solve(int n) {
  for (int i = n-2; i >= 0; i--) {
    if (a[i] > a[i+1])
      return i+1;
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> a[i];

  cout << solve(n) << '\n';

  return 0;
}
