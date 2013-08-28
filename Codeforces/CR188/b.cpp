#include <bits/stdc++.h>

using namespace std;

const string HEAVY = "heavy";
const string METAL = "metal";

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;

  int n = s.size();

  vector<int> h, m;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'h') {
      if (s.substr(i, 5) == HEAVY) {
        h.push_back(i);
        i += 4;
      }
    }
    else if (s[i] == 'm') {
      if (s.substr(i, 5) == METAL) {
        m.push_back(i);
        i += 4;
      }
    }
  }

  long long ans = 0;
  for (int i = 0; i < h.size(); i++) {
    int j = lower_bound(m.begin(), m.end(), h[i]) - m.begin();
    ans += (m.size() - j);
  }
  cout << ans << '\n';

  return 0;
}
