#include <bits/stdc++.h>

using namespace std;

string s;
const int N = 9;

bool matches(const string & t) {
  for (int i = 0; i < N; i++)
    if (s[i] != '*')
      if (s[i] != t[i])
        return false;
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string t;
  vector<string> ans;

  cin >> s;

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t;
    if (matches(t))
      ans.push_back(t);
  }

  cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << '\n';

  return 0;
}
