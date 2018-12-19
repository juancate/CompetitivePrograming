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

const int mod = INF+7;

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  string s, w;

  cin >> n >> s >> w;

  vector<long long> is(n), js(n);
  long long tis = 0, tjs = 0;

  for(int i = 0; i < n; i++) {
    if(s[i] == '?' && w[i] == '?') {
      is[i] += 45; // si > wi
      js[i] += 45; // si < wi
    }
    else if(s[i] == '?' && w[i] != '?') {
      for(char k = '0'; k < w[i]; k++)
        js[i]++;
      for(char k = w[i]+1; k <= '9'; k++)
        is[i]++;
    }
    else if(s[i] != '?' && w[i] == '?') {
      for(char k = '0'; k < s[i]; k++)
        is[i]++;
      for(char k = s[i]+1; k <= '9'; k++)
        js[i]++;
    }
    else {
      if(s[i] > w[i]) is[i]++;
      if(s[i] < w[i]) js[i]++;
    }
    tis = (tis + is[i]) % mod;
    tjs = (tjs + js[i]) % mod;
  }

  long long ans = 0;

  for(int i = 0; i < n; i++) {
    if(s[i] != '?' && w[i] != '?') {
      if(s[i] < w[i]) ans = (ans + tjs) % mod; // is i already
      else continue;
    }
    else {
      ans = (ans + ((tjs - js[i] + mod) % mod)) % mod;
    }
  }

  cout << ans << endl;

  return 0;
}

