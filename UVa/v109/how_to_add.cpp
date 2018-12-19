#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000;
const int maxn = 111;

long long memo[maxn][maxn];

long long solve(int N, int K) {
  for (int i = 0; i <= K; i++)
    memo[0][i] = 1;
  for (int i = 0; i <= N; i++)
    memo[i][1] = 1;

  memo[0][0] = 0;
  for (int i = 0; i <= N; i++) {
    for (int k = 2; k <= K; k++) {
      memo[i][k] = 0;
      for (int j = 0; j <= i; j++) {
        memo[i][k] += memo[j][k-1];
        if (memo[i][k] >= mod)
          memo[i][k] -= mod;
      }
    }
  }
  return memo[N][K];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve(100, 100);

  int N, K;
  while (cin >> N >> K) {
    if ((N|K) == 0)
      break;
    cout << memo[N][K] << '\n';
  }

  return 0;
}
