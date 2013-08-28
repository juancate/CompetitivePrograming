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

#define D(x) cerr << #x << " = " << (x) << endl
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

const int maxn = 2000001;

long long phi[maxn], dphi[maxn], sodf[maxn];

int calc_dphi(int i) {
  if(dphi[i] != -1) return dphi[i];
  return dphi[i] = 1 + calc_dphi(phi[i]);
}

int main() {
  for(int i = 0; i < maxn; i++) {
    phi[i] = i;
    dphi[i] = -1;
  }

  phi[1] = 0;
  for(int i = 2; i < maxn; i++) {
    if(phi[i] == i) { // i is prime
      for(int j = i; j < maxn; j += i) {
        phi[j] = (phi[j] * (i-1)) / i; // phi[j] * (1 - 1/i)
      }
    }
  }

  dphi[1] = 0;
  for(int i = 2; i < maxn; i++) {
    calc_dphi(i);
  }

  for(int i = 2; i < maxn; i++) {
    sodf[i] = dphi[i] + sodf[i-1];
  }

  int N;
  scanf("%d", &N);

  while(N--) {
    int n, m;
    scanf("%d%d", &m, &n);
    printf("%d\n", sodf[n] - sodf[m-1]);
  }

  return 0;
}

