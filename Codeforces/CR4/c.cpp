#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  map< string, vector<int> > m;
  vector<int> ini(1, 0);

  for(int i = 0; i < n; i++) {
    string s;
    cin >> s;
    if(m.count(s)) {
      vector<int>& v = m[s];
      int next = v.back()+1;
      cout << s << next << endl;
      v.push_back(next);
    }
    else {
      m[s] = ini;
      cout << "OK" << endl;
    }
  }

  return 0;
}
