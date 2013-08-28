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
  string f;
  cin >> n >> f;

  int s = -1, t = -1;

  for(int i = 0; i < n; i++)
    if(f[i] != '.') {
      s = i;
      break;
    }

  for(int i = 0; i < n; i++)
    if(f[i] == 'L') {
      t = i-1;
      break;
    }

  if(t == -1) {
    for(int i = n-1; i >= 0; i--) {
      if(f[i] != '.') {
        t = i+1;
        break;
      }
    }
  }

  cout << (s+1) << ' ' << (t+1) << endl;

  return 0;
}

