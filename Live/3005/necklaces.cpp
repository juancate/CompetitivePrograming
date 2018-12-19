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
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <complex>

#define D(x) cerr << #x << " = " << (x) << endl;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

int eval(string s, bool mode) {
  int n = s.size();
  int r = 0;
  for(int i = n-1; i >= 0; i--)
    if(!mode) {
      if(s[i] == 'B')
        r |= (1 << i);
    }
    else {
      if(s[i] == 'W')
        r |= (1 << i);
    }
  return r;
}

void check(int& min, int& max, int val) {
  min = std::min(min, val);
  max = std::max(max, val);
}

int main() {
  ios_base::sync_with_stdio(false);

  string s;
  while(cin >> s) {
    if(s == "END")
      break;

    int min, max;
    min = INF, max = -INF;

    int n = s.size();

    for(int i = 0; i < n; i++) {
      string t = s.substr(i) + s.substr(0, i);
      check(min, max, eval(t, 0));
      check(min, max, eval(t, 1));
      string u = s.substr(i+1);
      t = s.substr(0, i+1);
      reverse(ALL(u));
      reverse(ALL(t));
      t = t + u;
      check(min, max, eval(t, 0));
      check(min, max, eval(t, 1));
    }

    cout << min << " " << max << endl;
  }

  return 0;
}

