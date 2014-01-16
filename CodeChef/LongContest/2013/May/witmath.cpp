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

long long mulmod(long long a, long long b, long long c) {
  long long x = 0, y = a % c;

  while(b > 0) {
    if(b & 1) x = (x+y) % c;
    y = (y<<1) % c;
    b >>= 1;
  }

  return x;
}

long long pow(long long a, long long b, long long c) {
  long long x = 1, y = a;

  while(b > 0) {
    if(b & 1) x = mulmod(x, y, c);
    y = mulmod(y, y, c);
    b >>= 1;
  }

  return x;
}

bool miller_rabin(long long p, int k) {
  if(p < 2) return false;
  if(p == 2) return true;
  if(!(p & 1)) return false;

  long long s = p-1;
  while(!(s & 1))
    s >>= 1;

  while(k--) {
    long long a = rand() % (p-1) + 1;
    long long temp = s;

    long long mod = pow(a, temp, p);

    while(temp != p-1 && mod != 1 && mod != p-1) {
      mod = mulmod(mod, mod, p);
      temp <<= 1;
    }

    if(mod != p-1 && !(temp & 1))
      return false;
  }

  return true;
}

int main() {
  int t;
  scanf("%d", &t);

  while(t--) {
    long long n;
    scanf("%lld", &n);

    while(!miller_rabin(n, 3))
      n--;
    printf("%lld\n", n);
  }

  return 0;
}

