#include <bits/stdc++.h>

using namespace std;

string s;

string solve() {
  string t;
  int n = s.size();
  int pos = s.find('.');
  for (int i = n-1; i >= 0; i--) {
    if (s[i] == '.')
      break;
    t.push_back(s[i]);
  }
  t.push_back('.');
  int cnt = 0;
  for (int i = pos-1; i >= 0; i--, cnt++) {
    if (cnt == 3) {
      t.push_back(',');
      cnt = 0;
    }
    t.push_back(s[i]);
  }
  reverse(t.begin(), t.end());
  return t;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> s;

  bool neg = false;
  if (s[0] == '-') {
    neg = true;
    s = s.substr(1);
  }

  int n = s.size();
  int pos = s.find('.');
  if (pos == string::npos)
    s += ".00";
  else {
    if (n-pos-1 < 2) s += "0";
    else s = s.substr(0, pos+3);
  }

  if (neg) cout << '(';
  cout << "$" << solve();
  if (neg) cout << ')';
  cout << '\n';

  return 0;
}
