#include <bits/stdc++.h>

using namespace std;

int a[130], b[130];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int tc;
  cin >> tc;

  while (tc--) {
    string s, t;
    cin >> s >> t;

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);

    for (char c : s)
      a[c]++;
    for (char c : t)
      b[c]++;

    int ans = 0;
    for (int i = 0; i < 130; i++)
      ans += min(a[i], b[i]);

    cout << ans << '\n';
  }

  return 0;
}
