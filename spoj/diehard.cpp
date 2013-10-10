#include <bits/stdc++.h>

using namespace std;

int memo[3][2000][2000];

int ch[] = {3, -5, -20}; // air, water, fire
int ca[] = {2, -10, 5};

int dp(int el, int h, int a) {
  if (h <= 0 || a <= 0)
    return 0;
  if (memo[el][h][a] != -1)
    return memo[el][h][a];

  int ans = 0;
  for (int i = 0; i < 3; i++)
    if (i != el)
      ans = max(ans, 1 + dp(i, h+ch[i], a+ca[i]));
  return memo[el][h][a] = ans;
}

int main(int argc, const char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    int H, A;
    cin >> H >> A;
    memset(memo, -1, sizeof memo);
    int ans = 0;
    for (int i = 0; i < 3; i++)
      ans = max(ans, dp(i, H, A));
    cout << ans-1 << "\n\n";
  }

  return 0;
}
