#include <bits/stdc++.h>

#define foreach(it,v) \
  for (__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k, d;
  cin >> k >> d;

  if (d == 0) {
    if (k > 1)
      cout << "No solution\n";
    else
      cout << 0 << '\n';
    return 0;
  }

  cout << d;
  for (int i = 1; i < k; i++)
    cout << 0;
  cout << '\n';

  return 0;
}

