#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  string s;
  cin >> n >> s;

  int ans = 0;
  for (int j = 0; j < s.size(); j++) {
    if (j >= 3) {
      if ((j % n) == 0) {
        if (s[j-3] == s[j-2] && s[j-2] == s[j-1])
          s[j] = s[j-1], ans++;
      }
    }
  }
  cout << ans << endl;

  return 0;
}
