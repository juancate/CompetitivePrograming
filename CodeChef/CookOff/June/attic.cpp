#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000010;

char s[maxn];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    cin >> s;
    int l = 1;
    int ans = 0;

    for (int i = 0; s[i]; i++) {
      if (s[i] == '.') {
        int j = i;
        while (s[j] && s[j] == '.')
          j++;
        int curr = j-i+1;
        if (curr > l) {
          l = curr;
          ans++;
        }
        i = j-1;
      }
    }
    cout << ans << '\n';
  }

  return 0;
}

