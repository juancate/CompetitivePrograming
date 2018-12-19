#include <iostream>

using namespace std;

int t, n, i, j, ans, dp[100][100];

// Compressed solution
// using namespace std;int t,n,i,x,j,d[99][99];main(){cin>>t;while(cin>>n){x=0;for(i=1;i<=n;i++)for(j=1;j<=i;j++){cin>>d[i][j];d[i][j]+=max(d[i-1][j-1],d[i-1][j]);x=max(x,d[i][j]);}cout<<x<<'\n';}}

int main() {
  cin >> t;

  while (t--) {
    cin >> n;
    ans = 0;
    for (i = 0; i < n; i++)
      for (j = 0; j <= i; j++) {
        cin >> dp[i][j];
        if (i != 0) {
          if (j == 0) dp[i][j] += dp[i-1][j];
          else {
            if (j == i) dp[i][j] += dp[i-1][j-1];
            else dp[i][j] += max(dp[i-1][j-1], dp[i-1][j]);
          }
        }
        if (i == n-1) ans = max(ans, dp[i][j]);
      }
    cout << ans << '\n';
  }
}
