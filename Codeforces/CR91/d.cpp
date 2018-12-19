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

  int n, k;
  string d;
  cin >> n >> k >> d;

  vector<bool> seen(n);

  int x = 0;

  while(k--) {

    while(x < n-1) {
      if(d[x] == '4' && d[x+1] == '7')
        break;
      x++;
    }

    if(d[x] != '4' || d[x+1] != '7')
      break;

    if(seen[x]) {
      if((k+1) & 1) {
        if((x+1) & 1)
          d[x] = d[x+1] = '4';
        else
          d[x] = d[x+1] = '7';
      }
      break;
    }

    seen[x] = true;

    if((x+1) & 1) {
      d[x] = d[x+1] = '4';
      seen[x+1] = false;
    }
    else {
      d[x] = d[x+1] = '7';
      seen[x+1] = false;
      x--;
    }
  }

  cout << d << endl;

  return 0;
}

