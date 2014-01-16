#include <bits/stdc++.h>

using namespace std;

string f, s;
char to[26];

void solve() {
  int n = s.size();
  string t;

  vector< pair<int,char> > cnt;
  for (int i = 0; i < 26; i++)
    cnt.push_back(make_pair(0, i+'a'));

  for (int i = 0; i < n; i++) {
    if (isalpha(s[i])) {
      char ch = tolower(s[i]);
      cnt[ch-'a'].first++;
    }
  }

  sort(cnt.begin(), cnt.end());

  for (int i = 25; i >= 0; i--) {
    char curr = cnt[i].second;
    to[curr-'a'] = f[i];
  }

  for (int i = 0; i < n; i++) {
    char ch = s[i];
    if (isalpha(ch)) {
      ch = tolower(s[i]);
      if (isupper(s[i]))
        ch = toupper(to[ch-'a']);
      else
        ch = to[ch-'a'];
    }
    t.push_back(ch);
  }
  cout << t << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  cin.get();

  while (t--) {
    getline(cin, f);
    getline(cin, s);

    solve();
  }

  return 0;
}
