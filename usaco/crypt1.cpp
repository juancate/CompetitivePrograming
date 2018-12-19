/*
ID: jcamarg1
PROG: crypt1
LANG: C++
*/
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

int a[10];
bool seen[10];

int mul(int i, int j, int k, int l) {
  int x = i*100 + j*10 + k;
  return x*l;
}

bool check(int x, int size) {
  int sz = 0;
  while(x > 0) {
    int r = x % 10;
    if(!seen[r]) return false;
    x /= 10;
    sz++;
  }
  return sz == size;
}

int main() {
  freopen("crypt1.in", "r", stdin);
  freopen("crypt1.out", "w", stdout);

  memset(seen, 0, 10);

  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    seen[a[i]] = true;
  }

  int ans = 0;

  for(int i1 = 0; i1 < n; i1++) {
    for(int j1 = 0; j1 < n; j1++) {
      for(int k1 = 0; k1 < n; k1++) {
        for(int i2 = 0; i2 < n; i2++) {
          for(int j2 = 0; j2 < n; j2++) {
            int p1 = mul(a[i1],a[j1],a[k1], a[j2]);
            int p2 = mul(a[i1],a[j1],a[k1], a[i2]);
            if(check(p1, 3) && check(p2, 3)) {
              int sum = p1 + p2*10;
              if(check(sum, 4))
                ans++;
            }
          }
        }
      }
    }
  }

  printf("%d\n", ans);

  return 0;
}

