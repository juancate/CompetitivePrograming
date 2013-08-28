#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;
  int n = s.size();
  string ans = "";

  for (int i = 0; i < n; i++) {
    int letter = 0, j, k;
    for (j = i; j < n && letter < 2; j++) {
      if ('A' <= s[j] && s[j] <= 'Z')
        letter++;
    }

    if (letter > 1) j--;
    string curr = "";

    for (k = i; s[k] == '0'; k++);

    for (; k < j; k++) {
      if (isalpha(s[k])) curr.push_back('9');
      else curr.push_back(s[k]);
    }

    if (curr.size() == 0)
      curr = "0";

    if (curr.size() > ans.size())
      ans = curr;
    else if (curr.size() == ans.size())
      ans = max(ans, curr);
  }

  cout << ans << '\n';

  return 0;
}
