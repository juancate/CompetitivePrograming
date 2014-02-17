#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;

  int n = s.size();

  int ans = 0;
  for (int i = 0; i < n;) {
    char c = s[i];
    int len = 0;
    while (i < n && s[i] == c) i++, len++;

    if (len % 2 == 0) ans++;
  }
  cout << ans << '\n';

  return 0;
}
