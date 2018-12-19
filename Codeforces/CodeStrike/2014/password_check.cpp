#include <bits/stdc++.h>

using namespace std;

bool has(const string & s, char lo='a', char up='z') {
  for (int i = 0; i < s.size(); i++)
    if (s[i] >= lo && s[i] <= up)
      return true;
  return false;
}

bool is_complex(const string & s) {
  int n = s.size();
  return (n >= 5) && has(s) && has(s, 'A', 'Z') && has(s, '0', '9');
}

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;

  cout << (is_complex(s)? "Correct": "Too weak") << '\n';

  return 0;
}
