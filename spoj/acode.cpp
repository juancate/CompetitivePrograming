#include <bits/stdc++.h>

using namespace std;

int n;
char s[10010];

long long memo[10010];

long long solve(int index) {
  if (index == n)
    return 1;
  if (s[index] == '0')
    return 0;

  if (memo[index] != -1)
    return memo[index];

  long long ret = solve(index+1);
  int curr = s[index]-'0';

  if (index+1 < n) {
    curr = curr*10 + s[index+1]-'0';
    if (curr <= 26)
      ret += solve(index+2);
  }

  return memo[index] = ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> s) {
    if (s[0] == '0') break;
    n = strlen(s);
    for (int i = 0; i < n; i++) memo[i] = -1;
    cout << solve(0) << '\n';
  }

  return 0;
}
