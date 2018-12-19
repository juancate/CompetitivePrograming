#include <bits/stdc++.h>

#define foreach(it,v) \
  for (__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)

using namespace std;

const int N = 110;

bool digits[10];

bool check(int k) {
  for (int i = 0; i <= k; i++)
    if (!digits[i])
      return false;
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k, ans = 0;
  cin >> n >> k;

  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    memset(digits, 0, sizeof digits);
    for (int j = 0; j < s.size(); j++)
      digits[s[j]-'0'] = true;
    ans += check(k);
  }

  cout << ans << '\n';

  return 0;
}

