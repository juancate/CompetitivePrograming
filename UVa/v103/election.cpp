#include <bits/stdc++.h>

using namespace std;

int election[32];
string parties[32];

int main() {
  string s;
  getline(cin, s);

  int t = atoi(s.c_str());

  while(t--) {
    getline(cin, s);
    getline(cin, s);
    int n = atoi(s.c_str());

    map<string, int> mt;

    for(int i = 0; i < n; i++) {
      string name, party;
      getline(cin, name);
      mt[name] = i;

      getline(cin, party);
      parties[mt[name]] = party;
    }

    getline(cin, s);
    int m = atoi(s.c_str());
    memset(election, 0, sizeof(election));

    for(int i = 0; i < m; i++) {
      string name;
      getline(cin, name);

      if(mt.count(name))
        election[mt[name]]++;
    }

    int best = 0;
    for(int i = 1; i < n; i++)
      if(election[best] < election[i])
        best = i;

    bool tie = false;
    for(int i = 0; i < n; i++) {
      if(i == best) continue;
      if(election[i] == election[best]) {
        tie = true;
        break;
      }
    }

    string ans = tie? "tie" : parties[best];

    cout << ans << endl;
    if(t) cout << endl;
  }
  return 0;
}
