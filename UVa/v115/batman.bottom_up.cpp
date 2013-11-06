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

    for (int i = 0; i <= V; i++)
        memo[i][0] = INF;

    for (int i = 0; i <= N; i++)
      memo[0][i] = 0;

    for (int i = 1; i <= V; i++) {
      for (int j = 1; j <= N; j++) {
        memo[i][j] = memo[i][j-1];
        if (affects[i][j])
          memo[i][j] = min(memo[i][j], cost[j] + memo[i-1][j-1]);
      }
    }

    long long ans = memo[V][N];

    cout << ((ans <= E)? "Yes" : "No") << '\n';
  }

  return 0;
}
