#include <bits/stdc++.h>

using namespace std;

struct cmp {
  bool operator()(string a, string b) {
    if (a.size() != b.size()) {
      int n = min(a.size(), b.size());
      if (a.substr(0,n) == b.substr(0,n))
        return a.size() == n;
    }
    return a > b;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    priority_queue<string,vector<string>,cmp > Q;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      Q.push(s);
    }

    string ans;
    while (!Q.empty()) {
      string curr = Q.top();
      Q.pop();

      ans.push_back(curr[0]);
      if (curr.size() > 1)
        Q.push(curr.substr(1));
    }

    cout << ans << endl;
  }

  return 0;
}
