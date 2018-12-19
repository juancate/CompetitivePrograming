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
  long long n, k;
  cin >> n >> k;
  n--; k--;

  long long sum = k * (k + 1) / 2;
  if(n == 0) {
    cout << 0 << endl;
    return 0;
  }
  if(n > sum) {
    cout << -1 << endl;
    return 0;
  }

  long long lo = 1, hi = k+1;

  while(lo < hi) {
    long long mid = lo + (hi - lo) / 2;

    long long curr = (k+mid)*(k-mid+1) / 2;
    if(curr < n) hi = mid;
    else lo = mid+1;
  }
  lo--;
  cout << (k - lo + 1) << endl;

  return 0;
}

