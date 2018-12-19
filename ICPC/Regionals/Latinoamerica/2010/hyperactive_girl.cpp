#include <bits/stdc++.h>

using namespace std;

const int maxn = 111;
const int mod = 100000000;

int N, M;
pair<int,int> t[maxn];
long long memo[maxn][maxn];

long long dp(int prev, int curr) {
  if (t[curr].second >= M)
    return 1;

  if (memo[prev][curr] != -1)
    return memo[prev][curr];

  long long r = 0;

  for (int next = curr+1; next <= N; next++) {
    if (t[next].first > t[curr].first &&
        t[next].first <= t[curr].second &&
        t[next].second > t[curr].second)
    {
      if (prev == curr) {
        r += dp(curr, next);
      }
      else {
        if (t[next].first > t[prev].second)
          r += dp(curr, next);
      }
    }
    if (r >= mod)
      r -= mod;
  }

  return memo[prev][curr] = r;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> M >> N) {
    if ((N|M) == 0)
      break;

    for (int i = 1; i <= N; i++)
      cin >> t[i].first >> t[i].second;
    sort(t+1, t+N+1);

    memset(memo, -1, sizeof memo);

    long long ans = 0;
    for (int i = 1; i <= N; i++) {
      if (t[i].first == 0) {
        ans += dp(i, i);
        if (ans >= mod)
          ans -= mod;
      }
    }
    cout << ans << '\n';
  }

  return 0;
}
