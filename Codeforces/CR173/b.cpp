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

char ans[1000010];
int a[1000010], b[1000010], sa, sb, n;

void solve(int t) {
  for(int i = 0; i < n; i++) {
    if(t == 0) {
      if(abs(sa+a[i]-sb) > 500) {
        t = 1-t;
        i--;
        continue;
      }
      sa += a[i];
      ans[i] = 'A';
    }
    else {
      if(abs(sb+b[i]-sa) > 500) {
        t = 1-t;
        i--;
        continue;
      }
      sb += b[i];
      ans[i] = 'G';
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;

  for(int i = 0; i < n; i++)
    cin >> a[i] >> b[i];

  sa = sb = 0;
  int t = 0;
  solve(t);
  ans[n] = 0;

  if(abs(sa-sb) <= 500) {
    cout << ans << endl;
    return 0;
  }

  sa = sb = 0;
  t = 1;
  solve(t);
  ans[n] = 0;

  if(abs(sa-sb) <= 500) {
    cout << ans << endl;
    return 0;
  }

  cout << -1 << endl;
  return 0;
}

