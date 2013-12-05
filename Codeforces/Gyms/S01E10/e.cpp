#include <bits/stdc++.h>

using namespace std;

string solve(int e, int g) {
  string ans = "NO";

  if (e + 1 == g + 6) {
    if (g < 1)
      ans = "YES";
    else if (g == 1)
      ans = "PENALTIES";
  }
  else {
    if (e + 1 > g + 6)
      ans = "YES";
  }

  return ans;
}

int main() {
  freopen("ghanophobia.in", "r", stdin);

  int t;
  scanf("%d", &t);

  for (int tc = 1; tc <= t; tc++) {
    int e, g;
    scanf("%d:%d", &e, &g);

    string ans = solve(e, g);
    printf("Case %d: %s\n", tc, ans.c_str());
  }

  return 0;
}
