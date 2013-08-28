#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
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

#define D(x) cerr << #x << " = " << x << endl;
#define REP(i,n) for(int i=0; i<n; i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)

#define INF 1<<30
#define EPS 1e-13

using namespace std;

long long n, m, k, xc, yc;

bool valid(long long x, long long y) {
  return (x >= 1 and x <= n and y >= 1 and y <= m);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m >> xc >> yc >> k;
  long long ans = 0;
  REP(i,k) {
    long long dx, dy;
    cin >> dx >> dy;
    
    long long fact = INF;
    if(dx > 0) fact = (n - xc) / dx;
    else if(dx < 0) fact = (xc - 1) / -dx;
    if(dy > 0) fact = min(fact, (m - yc) / dy);
    else if(dy < 0) fact = min(fact, (yc - 1) / -dy);

    xc = xc + fact*dx;
    yc = yc + fact*dy;
    ans += fact;
    /*
    for(long long fact = 1000000000; fact > 0; fact /= 2) {
      while(valid(xc + fact*dx, yc + fact*dy)) {
        xc = xc + fact*dx;
        yc = yc + fact*dy;
        ans += fact;
      }
    }
    */
  }
  cout << ans << endl;
}

