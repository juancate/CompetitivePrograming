#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int process(int i, char ch) {
  string t;
  int j = i;

  for (; j < n; j++) {
    if (s[j] == ch)
      break;
    t.push_back(s[j]);
  }

  cout << '<' << t << ">\n";
  return j;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  getline(cin,s);

  n = s.size();

  for (int i = 0; i < n; i++) {
    if (s[i] == '"')
      i = process(i+1, '"');
    else if (s[i] != ' ')
      i = process(i, ' ');
  }

  return 0;
}
