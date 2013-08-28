#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long long n, k;
  cin >> n >> k;

  long long mid = (n+1) >> 1;

  if (k <= mid) {
    k--;
    cout << (2*k + 1) << '\n';
  }
  else {
    k -= mid;
    cout << 2*k << '\n';
  }

  return 0;
}
