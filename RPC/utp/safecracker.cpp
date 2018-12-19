#include <bits/stdc++.h>

using namespace std;

int target;
string s, ans;
bool can;

inline long long ord(char ch) {
  return ch-'A'+1;
}

void solve(const string & t, int i) {
  int n = t.size();
  if (n == 5) {
    string c = t;
    sort(c.begin(), c.end());

    do {
      long long r = ord(c[0]) - ord(c[1]) * ord(c[1]) +
                    ord(c[2]) * ord(c[2]) * ord(c[2]) -
                    ord(c[3]) * ord(c[3]) * ord(c[3]) * ord(c[3]) +
                    ord(c[4]) * ord(c[4]) * ord(c[4]) * ord(c[4]) * ord(c[4]);

      if (r == target) {
        ans = max(ans, c);
        can = true;
      }
    } while (next_permutation(c.begin(), c.end()));

    return;
  }

  if (i < s.size()) {
    string next = t;
    next.push_back(s[i]);
    solve(next, i+1);
    solve(t, i+1);
  }
}

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> target >> s) {
    if (target == 0 && s == "END")
      break;
    ans = "";
    can = false;
    string t = "";
    solve(t, 0);
    cout << (can? ans : "no solution") << '\n';
  }

  return 0;
}
