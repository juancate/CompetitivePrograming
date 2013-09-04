#include <bits/stdc++.h>

using namespace std;

long long lcm(long long a, long long b) {
  return (a * b) / __gcd(a,b);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long long x, y, a, b;
  cin >> x >> y >> a >> b;

  long long l = lcm(x, y);
  int end = b / l;

  int ans = 0;
  if (end != 0) {
    int start = a / l;
    if (start != 0)
      ans = end-start + (a % l == 0);
    else
      ans = end;
  }

  cout << ans << '\n';

  return 0;
}
