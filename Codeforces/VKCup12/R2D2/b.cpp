#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s, t;
  cin >> s >> t;

  int n = s.size(), m = t.size();

  priority_queue<char> pq;
  for (int i = 0; i < m; i++)
    pq.push(t[i]);

  for (int i = 0; i < n; i++) {
    if (pq.empty())
      break;
    char ch = pq.top();
    if (ch > s[i]) {
      s[i] = ch;
      pq.pop();
    }
  }

  cout << s << '\n';

  return 0;
}
