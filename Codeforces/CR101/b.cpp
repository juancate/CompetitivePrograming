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

  int a, x, y;
  cin >> a >> x >> y;

  if(y <= a) {
    if(0 < y && y < a && -a/2. < x && x < a/2.)
      cout << 1 << endl;
    else
      cout << -1 << endl;
    return 0;
  }

  int row = 1, t = 0, ans;

  for(int cy = a+a; cy < y+a; cy += a) {
    ans = -1;
    if(cy-a < y && y < cy) {
      if(t == 0) {
       if(-a/2. < x && x < a/2.)
          ans = row+1;
      }
      else {
        if(-a < x && x < 0)
          ans = row+1;
        else if(0 < x && x < a)
          ans = row+2;
      }
    }
    row += t? 2 : 1;
    t ^= 1;
  }

  cout << ans << endl;

  return 0;
}

