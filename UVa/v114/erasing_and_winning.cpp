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

// UNSOLVED

int main() {
  ios_base::sync_with_stdio(false);

  string s;
  int n, d, i;

  while(cin >> n >> d >> s) {
    list<char> v(ALL(s));
    list<char>::iterator l, r;
    l = v.begin();
    r = l;
    r++;

    for(i = 0; i < d; i++) {
      for(; r != v.end(); l++, r++)
        if(*l < *r)
          break;
      r = v.erase(l);
      if(r == v.begin())
        r++;
      l = r;
      l--;
    }
    string ans(ALL(v));
    cout << ans << endl;
  }
  return 0;
}

