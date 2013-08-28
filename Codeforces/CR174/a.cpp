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

int modpow(int x, int p, int mod) {
  int ans = 1;

  while(p > 0) {
    if(p & 1) ans = (ans * x) % mod;
    x = (x * x) % mod;
    p >>= 1;
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  int ans = 0;

  for(int x = 1; x < n; x++) {
    bool ok = true;
    for(int p = 1; p < n-1; p++) {
      int y = modpow(x,p,n) - 1;
      if((y % n) == 0) {
        ok = false;
        break;
      }
    }
    if(ok) {
      int y = modpow(x,n-1,n) - 1;
      if((y % n) == 0) {
        ans++;
      }
    }
  }

  cout << ans << endl;

  return 0;
}

