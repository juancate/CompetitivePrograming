#include <bits/stdc++.h>

using namespace std;

const long long INF = (long long)1e18;

const int maxn = 1010;

int N, V, E, offense[maxn], cost[maxn], defense[maxn];
long long memo[maxn][maxn];
bool affects[maxn][maxn];

map<string, int> powers;

void process(int i) {
  string s;
  cin >> s;
  int n = s.size(), j = 0;

  while (j < n) {
    string t;
    while (j < n && s[j] != ',')
      t.push_back(s[j++]);
    j++;
    int k = powers[t];
    if (defense[i] <= offense[k])
      affects[i][k] = true;
  }
}

long long dp(int v, int p) {
  if (v == 0)
    return 0;
  if (v > 0 && p == 0)
    return INF;

  if (memo[v][p] != -1)
    return memo[v][p];

  long long r = INF;
  for (int j = 1; j <= p; j++) {
    if (affects[v][j])
      r = min(r, cost[j] + dp(v-1, j-1));
  }
  return memo[v][p] = r;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> N >> V >> E) {
    if ((N|V|E) == 0)
      break;

    string s;
    powers.clear();
    for (int i = 1; i <= N; i++) {
      cin >> s >> offense[i] >> cost[i];
      powers[s] = i;
    }

    memset(affects, 0, sizeof affects);
    for (int i = 1; i <= V; i++) {
      cin >> s >> defense[i];
      process(i);
    }

    memset(memo, -1, sizeof memo);
    long long ans = dp(V, N);

    cout << ((ans <= E)? "Yes" : "No") << '\n';
  }

  return 0;
}
