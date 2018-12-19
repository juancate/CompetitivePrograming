#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
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
#include <climits>

#define D(x) cerr << #x << " = " << (x) << endl;
#define REP(i,n) for(int i=0; i<n; i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

const int INF = 100000000;
const long long INFLL = 1000000000000000000LL;
const double EPS = 1e-13;

// 907 - Winterim Backpacking Trip
// Algorithm: Binary Search
// Protip: Test with cases they give you in stament but no in input examples

using namespace std;

const int MAXN = 600 + 10;

int N, K;
int campdist[MAXN];

bool check(int dist) {
  int cnt, sumdist;
  cnt = sumdist = 0;
  REP(i, N+1) {
    if(campdist[i] > dist) return false;
    if(campdist[i] + sumdist > dist) {
      sumdist = 0;
      cnt++;
    }
    sumdist += campdist[i];
  }
  return (cnt <= K);
}

int binarySearch() {
  int lo = 1, hi = INF;
  while(lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if(check(mid)) hi = mid;
    else lo = mid + 1;
  }
  return lo;
}

int main() {
  while(scanf("%d %d", &N, &K) == 2) {
    REP(i, N+1) scanf("%d", &campdist[i]);
    printf("%d\n", binarySearch());
  }
}

