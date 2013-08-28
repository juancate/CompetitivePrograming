#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> l, r;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;
  int n = s.size();

  for (int i = 0; i < n; i++) {
    if (s[i] == 'l')
      l.push_back(i+1);
    else
      r.push_back(i+1);
  }

  for (int i = 0; i < r.size(); i++)
    cout << r[i] << '\n';
  for (int i = l.size()-1; i >= 0; i--)
    cout << l[i] << '\n';

  return 0;
}
