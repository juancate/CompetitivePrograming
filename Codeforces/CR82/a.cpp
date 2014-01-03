#include <bits/stdc++.h>

using namespace std;

const string cards = "6789TJQKA";
int m[128];

bool solve(string s, string a, string b) {
  if (a[1] == b[1])
    return m[a[0]] > m[b[0]];
  else {
    if (a[1] == s[0])
      return true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  for (int i = 0; i < cards.size(); i++)
    m[cards[i]] = i;

  string s, a, b;
  cin >> s >> a >> b;

  cout << (solve(s,a,b)? "YES" : "NO") << '\n';

  return 0;
}
