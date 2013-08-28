#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cassert>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

#define D(x) cerr << #x << " = " << x << endl
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

using namespace std;

string s1, s2;
int dp[1111][1111], sol[1111][1111];

void solve() {
  int n = s1.size();
  int m = s2.size();

  for(int i = 0; i <= m; i++) {
    dp[i][0] = i;
    sol[i][0] = 0;
  }
  for(int i = 0; i <= n; i++) {
    dp[0][i] = i;
    sol[0][i] = 1;
  }

  sol[0][0] = -1;

  for(int i = 1; i <= m; i++) {
    for(int j = 1; j <= n; j++) {
      if(s1[j-1] == s2[i-1]) {
        dp[i][j] = dp[i-1][j-1];
        sol[i][j] = 3;
      }
      else {
        dp[i][j] = 1 + dp[i-1][j];
        sol[i][j] = 0;

        if(dp[i][j-1] + 1 < dp[i][j]) {
          dp[i][j] = dp[i][j-1]+1;
          sol[i][j] = 1;
        }
        if(dp[i-1][j-1] + 1 < dp[i][j]) {
          dp[i][j] = dp[i-1][j-1]+1;
          sol[i][j] = 2;
        }
      }
    }
  }

  cout << dp[m][n] << endl;
}

int pos;
void print(int m, int n) {
  if(sol[m][n] != -1) {
    switch(sol[m][n]) {
      case 3:
        print(m-1, n-1);
      break;
      case 2:
        print(m-1, n-1);
        cout << "REPLACE " << n+pos << " " << s2[m-1] << endl;
      break;
      case 1:
        print(m, n-1);
        cout << "DELETE " << n+pos << endl;
        pos--;
      break;
      case 0:
        print(m-1, n);
        cout << "INSERT " << n+pos+1 << " " << s2[m-1] << endl;
        pos++;
      break;
    }
  }
}


int main() {
  ios_base::sync_with_stdio(false);
  cin >> s1 >> s2;

  pos = 0;
  solve();
  print(s2.size(), s1.size());

  return 0;
}

