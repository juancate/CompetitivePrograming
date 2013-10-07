#include <bits/stdc++.h>

#define foreach(it,v) \
  for (__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  int fives = 0, zeroes = 0;
  for (int i = 0, a; i < n; i++) {
    cin >> a;
    if (a == 5) fives++;
    else zeroes++;
  }

  if (zeroes == 0) {
    cout << -1 << '\n';
    return 0;
  }

  if (fives < 9) {
    cout << 0 << '\n';
    return 0;
  }

  int total = fives / 9;

  for (int i = 0; i < total; i++)
    for (int j = 0; j < 9; j++)
      cout << 5;
  for (int i = 0; i < zeroes; i++)
    cout << 0;
  cout << '\n';

  return 0;
}

