#include <bits/stdc++.h>

using namespace std;

const int maxn = 10010;

const unsigned long long p = 13331;

// Algorithm: String (Rabin Karp) + DP

string s[maxn];
int N, pos[maxn], len[maxn], dp[maxn];
unsigned long long H[maxn][1010], P[maxn];

vector<int> g[maxn];

void hash(int i) {
  int n = len[i];
  for (int j = 0; j < n; j++) {
    H[i][j] = (s[i][j] - 'a' + 1) * P[j];
    if (j) H[i][j] += H[i][j-1];
  }
}

bool cmp_len(int i, int j) {
  return len[i] < len[j];
}

inline
unsigned long long get_hash(int i, int l, int r) {
  return H[i][r] - (l ? H[i][l-1] : 0);
}

bool can(int ii, int jj) {
  unsigned long long h1 = get_hash(ii, 0, len[ii]-1), h2;

  for (int i = 0; i + len[ii] - 1 < len[jj]; i++) {
    h2 = get_hash(jj, i, i+len[ii]-1);
    if (h1 * P[i] == h2)
      return true;
  }
  return false;
}

int solve(int i) {
  if (dp[i] != -1)
    return dp[i];

  int r = 0;
  for (int j = g[i].size()-1; j >= 0; j--)
    r = max(r, 1 + solve(g[i][j]));
  return dp[i] = r;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  P[0] = 1;
  for (int i = 1; i < maxn; i++)
    P[i] = p * P[i-1];

  while (cin >> N) {
    if (N == 0)
      break;

    for (int i = 0; i < N; i++) {
      cin >> s[i];
      len[i] = s[i].size();
      pos[i] = i;
      hash(i);
    }
    sort(pos, pos+N, cmp_len);

    for (int i = 0; i < N; i++) {
      g[pos[i]].clear();
      for (int j = 0; j < i; j++) {
        if (len[pos[j]] >= len[pos[i]])
          break;
        if (can(pos[j], pos[i]))
          g[pos[i]].push_back(pos[j]);
      }
    }

    int ans = 0;
    memset(dp, -1, sizeof dp);

    for (int i = 0; i < N; i++)
      ans = max(ans, 1 + solve(pos[i]));
    cout << ans << '\n';
  }

  return 0;
}
