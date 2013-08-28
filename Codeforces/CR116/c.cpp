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

#define D(x) cerr << #x << " = " << x << endl;
#define REP(i,n) for(int i=0; i<n; i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  string w;
  cin >> w;
  int n = w.size();

  vector<int> upcase(n+1), lowcase(n+1);
  upcase[0] = 0;

  REP(i, n) {
    upcase[i+1] = upcase[i];
    if (w[i] >= 'A' and w[i] <= 'Z') {
      upcase[i+1]++;
    }
  }

  lowcase[0] = 0;

  REP(i, n) {
    lowcase[i+1] = lowcase[i];
    if (w[i] >= 'a' and w[i] <= 'z') {
      lowcase[i+1]++;
    }
  }

  int ans = INF;

  REP(i, n+1) {
    int curr = lowcase[i] + upcase[n] - upcase[i];
    ans = min(ans, curr);
  }

  cout << ans << endl;
}

