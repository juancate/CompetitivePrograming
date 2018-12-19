#include <bits/stdc++.h>

#define foreach(it,v) for (__typeof((v).begin()) it=(v).begin(); it!=(v).end(); it++)

using namespace std;

#define DIAG 0
#define BOTH 1

const int maxn = 111;

string a,b,v;
set<string> s[maxn][maxn];
int opt, dp[maxn][maxn], sol[maxn][maxn];

string solve() {
  int n = a.size();
  int m = b.size();

  for (int i = 0; i < maxn; i++)
    s[i][0].insert("");
  for (int i = 0; i < maxn; i++)
    s[0][i].insert("");

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i] == b[j]) {
        dp[i+1][j+1] = 1 + dp[i][j];
        foreach(it, s[i][j])
          s[i+1][j+1].insert(*it + a[i]);
      }
      else {
        if (dp[i+1][j] > dp[i][j+1]) {
          dp[i+1][j+1] = dp[i+1][j];
          foreach(it, s[i+1][j])
            s[i][j].insert(*it);
        }
        else if (dp[i+1][j] == dp[i][j+1]) {
          dp[i+1][j+1] = dp[i+1][j];
          foreach(it, s[i+1][j])
            s[i][j].insert(*it);
          foreach(it, s[i][j+1])
            s[i][j].insert(*it);
        }
        else {
          dp[i+1][j+1] = dp[i][j+1];
          foreach(it, s[i][j+1])
            s[i][j].insert(*it);
        }
      }
    }
  }

  int best = dp[n][m];

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (dp[i][j] == best) {
        foreach(it, s[i][j]) {
          cerr << *it << '\n';
          if (it->size() == best && it->find(v) == string::npos)
            return *it;
        }
      }
    }
  }

  return "";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> a >> b >> v;

  memset(dp, 0, sizeof(dp));
  memset(sol, -1, sizeof(sol));
  string ans = solve();
  if (ans == "") ans = "0";
  cout << ans << '\n';

  return 0;
}
