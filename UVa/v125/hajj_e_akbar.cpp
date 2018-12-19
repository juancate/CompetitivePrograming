#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  int tc = 1;

  while (cin >> s) {
    if (s == "*")
      break;

    cout << "Case " << tc++ << ": ";
    if (s == "Hajj")
      cout << "Hajj-e-Akbar\n";
    else
      cout << "Hajj-e-Asghar\n";
  }

  return 0;
}
