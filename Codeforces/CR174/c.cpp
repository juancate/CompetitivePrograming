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

long long op[200010], s[200010];

int main() {
  ios_base::sync_with_stdio(false);
  cout.precision(20);
  cout.setf(ios::fixed);
  int n, sz;
  cin >> n;

  long long sum;
  sum = 0; sz = 1;
  op[0] = 0;
  for(int i = 0; i < n; i++) {
    int t;
    cin >> t;

    if(t == 1) {
      int a, x;
      cin >> a >> x;
      sum += a*x;
      op[a-1] += x;
    }
    else if(t == 2) {
      int k;
      cin >> k;
      s[sz] = k;
      op[sz] = 0;
      sum += k;
      sz++;
    }
    else {
      sz--;
      sum -= s[sz];
      sum -= op[sz];
      op[sz-1] += op[sz];
    }
    double avg = (double)sum / (double)sz;
    cout << avg << endl;
  }

  return 0;
}

