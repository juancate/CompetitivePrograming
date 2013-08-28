#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[10010], f[5000], p[5000];

int main() {
  int n, m, c;
  while(scanf("%d %d.%d", &n, &m, &c)) {
    if(!(n|m|c)) break;
    m = 100*m + c;

    for(int i = 0; i < n; i++) {
      scanf("%d %d.%d", &f[i], &p[i], &c);
      p[i] = 100*p[i] + c;
    }

    memset(dp, 0, sizeof dp);
    for(int w = 1; w <= m; w++) {
      for(int i = 0; i < n; i++) {
        if(w - p[i] >= 0) {
          dp[w] = max(dp[w], dp[w-p[i]] + f[i]);
        }
      }
    }
    printf("%d\n", dp[m]);
  }
  return 0;
}
