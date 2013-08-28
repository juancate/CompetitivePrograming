#include <bits/stdc++.h>

using namespace std;

string putdot(string s) {
  int pos;
  while((pos = s.find("dot")) != string::npos) {
    s.replace(pos, 3, ".");
  }
  return s;
}

string putat(string s) {
  int pos = s.find("at");
  if(pos != string::npos) {
    s.replace(pos, 2, "@");
  }
  return s;
}

int main() {
  ios_base::sync_with_stdio(false);

  string mail;
  cin >> mail;

  int n = mail.size();

  mail = mail[0] + putdot(mail.substr(1, n-2)) + mail[n-1];
  n = mail.size();
  mail = mail[0] + putat(mail.substr(1, n-2)) + mail[n-1];

  cout << mail << endl;

  return 0;
}
