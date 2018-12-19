#include <bits/stdc++.h>

using namespace std;

string trans(string s) {
  int n = s.size();
  for (int i = 0; i < n-1; i++) {
    if (s[i] == ':' && s[i+1] == ':')
      return s = s.substr(0, i+1) + " " + s.substr(i+1);
  }
  return s;
}

vector<string> split(string s) {
  vector<string> vs;
  int n = s.size();

  for (int i = 0; i < n; i++) {
    string t;
    while (i < n && s[i] != ':')
      t.push_back(s[i++]);
    vs.push_back(t);
  }

  return vs;
}

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  cin.get();
  while (n--) {
    string ip;
    getline(cin, ip);

    ip = trans(ip);
    vector<string> blocks = split(ip);

    int miss = 8 - blocks.size() + 1;
    stringstream ss;
    for (int i = 0; i < blocks.size(); i++) {
      if (blocks[i] == " ") {
        while (miss--)
          ss << "0000:";
      }
      else {
        int zeros = 4 - blocks[i].size();
        while (zeros--)
          ss << '0';
        ss << blocks[i] << ':';
      }
    }

    string ans = ss.str();
    ans = ans.substr(0, ans.size()-1);
    cout << ans << endl;
  }

  return 0;
}
