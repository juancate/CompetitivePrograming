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

  string s;
  cin >> s;

  int n = s.size();
  string ans(n, ' ');

  for(int i = 0; i < n; i++) {
    ans[i] = s[i];
    if(s[i] == '4' || s[i] == '7')
      continue;

    if(s[i] < '4')
      ans[i] = '4';
    else
      ans[i] = '7';
  }
  int fours = count(ALL(ans), '4');
  int sevens = count(ALL(ans), '7');

  cout << ans << endl;

  return 0;
}

