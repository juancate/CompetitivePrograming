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

int main() {
  ios_base::sync_with_stdio(false);

  int n;
  string s;
  cin >> n >> s;

  string a(n, '0');
  string b(n, '1');

  for(int i = 0; i < n; i+=2) {
    a[i] = '1';
    b[i] = '0';
  }

  int ans = INF, cnt = 0;

  for(int i = 0; i < n; i++)
    if(s[i] != a[i])
      cnt++;

  ans = min(ans, cnt);

  cnt = 0;
  for(int i = 0; i < n; i++)
    if(s[i] != b[i])
      cnt++;

  ans = min(ans, cnt);

  cout << ans << endl;

  return 0;
}

