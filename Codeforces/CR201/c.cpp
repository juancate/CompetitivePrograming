#include <bits/stdc++.h>

#define foreach(it,v) for (__typeof((v).begin()) it=(v).begin(); it!=(v).end(); it++)

using namespace std;

const int INF = int(2e9);
const int maxn = 111;

int n, a[maxn];

int solve(int lo) {
  int total = a[n-1] / lo;
  return n-total;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a+n);

  int lo = a[0];
  for (int i = 1; i < n; i++)
    lo = __gcd(lo, a[i]);

  int ans = solve(lo);

  if (ans & 1) cout << "Alice\n";
  else cout << "Bob\n";

  return 0;
}
