#include <bits/stdc++.h>

using namespace std;

vector<string> t;

void printline(int n) {
  for (int i = 0; i < n; i++)
    cout << '*';
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  int length = 0;
  while (getline(cin,s)) {
    t.push_back(s);
    length = max(length, (int)s.size());
  }

  printline(length+2);
  bool f = false;

  for (int i = 0; i < t.size(); i++) {
    cout << '*';
    int diff = length-t[i].size();
    int l = diff / 2;
    int r = diff / 2;

    if ((length & 1) != (t[i].size() & 1)) {
      if (!f) r += diff % 2;
      else l += diff % 2;
      f ^= 1;
    }

    for (int j = 0; j < l; j++) cout << ' ';
    cout << t[i];
    for (int j = 0; j < r; j++) cout << ' ';

    cout << "*\n";
  }

  printline(length+2);

  return 0;
}
