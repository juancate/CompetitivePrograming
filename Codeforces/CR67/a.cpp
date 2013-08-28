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

int remove_zeros(int x) {
  int ret = 0;
  int p = 1;

  while(x > 0) {
    if(x % 10 > 0) {
      ret += (x % 10) * p;
      p *= 10;
    }
    x /= 10;
  }
  return ret;
}


int main() {
  ios_base::sync_with_stdio(false);
  int a, b, c;
  cin >> a >> b;

  c = a+b;

  a = remove_zeros(a);
  b = remove_zeros(b);
  c = remove_zeros(c);

  if(a + b == c) cout << "YES\n";
  else cout << "NO\n";

  return 0;
}

