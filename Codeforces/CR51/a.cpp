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
  cin >> n;

  vector<bool> seen(n+1, false);
  int k = 0, pos = 0;
  for(;;) {
    if(seen[pos])
      break;
    seen[pos] = true;
    pos = (pos + k + 1) % n;
    k++;
  }

  for(int i = 0; i < n; i++) {
    if(!seen[i]) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";

  return 0;
}

