#include <bits/stdc++.h>

using namespace std;

const int INF = int(1e9);

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;

  int n = s.size();

  int best = -INF;
  for (int i = 0; i < n; i++) {
    int last = i;
    int curr = 1;
    for (int j = i+1; j < n; j++) {
      if (s[j] == s[i]) {
        int dist = j - last;
        if (dist & 1) {
          last = j;
          curr++;
        }
      }
    }
    best = max(best, curr);
  }

  cout << best << '\n';

  return 0;
}
