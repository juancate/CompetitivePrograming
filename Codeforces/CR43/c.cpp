#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  string s;
  cin >> n >> s;

  int t = 0;
  for (int i = 0; i < n; i++)
    t += s[i] == 'T';

  int best = int(1e9);
  for (int i = 0; i < n; i++) {
    int curr = 0;
    for (int j = 0; j < t; j++) {
      if (s[(i+j) % n] == 'H')
        curr++;
    }
    best = min(best, curr);
  }

  cout << best << '\n';

  return 0;
}
