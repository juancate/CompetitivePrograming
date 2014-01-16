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

const int maxn = 100010;

struct node {
  int min, max;
} t[maxn<<2];

int a[maxn];

void build(int v, int tl, int tr) {
  if(tl == tr) {
    t[v].min = t[v].max = a[tl];
  }
  else {
    int tm = (tl + tr) >> 1;
    int next = v << 1;
    build(next, tl, tm);
    build(next+1, tm+1, tr);

    t[v].min = std::min(t[next].min, t[next+1].min);
    t[v].max = std::max(t[next].max, t[next+1].max);
  }
}

int getmin(int v, int tl, int tr, int l, int r) {
  if(l > tr || r < tl)
    return INF;

  if(l <= tl && tr <= r)
    return t[v].min;

  int tm = (tl+tr) >> 1;
  int next = v << 1;

  int left_min = getmin(next, tl, tm, l, r);
  int right_min = getmin(next+1, tm+1, tr, l, r);

  return std::min(left_min, right_min);
}

int getmax(int v, int tl, int tr, int l, int r) {
  if(l > tr || r < tl)
    return -INF;

  if(l <= tl && tr <= r)
    return t[v].max;

  int tm = (tl+tr) >> 1;
  int next = v << 1;

  int left_max = getmax(next, tl, tm, l, r);
  int right_max = getmax(next+1, tm+1, tr, l, r);

  return std::max(left_max, right_max);
}

int main() {
  int n, q, i, l, r;
  scanf("%d", &n);

  for(i = 0; i < n; i++)
    scanf("%d", a+i);

  build(1, 0, n-1);

  scanf("%d", &q);
  while(q--) {
    scanf("%d%d", &l, &r);
    int first = getmin(1, 0, n-1, l, r);
    int left_part = -INF, right_part = -INF;

    if(l > 0)
      left_part = getmax(1, 0, n-1, 0, l-1);
    if(r < n-1)
      right_part = getmax(1, 0, n-1, r+1, n-1);

    int best = std::max(left_part, right_part);

    double ans = first;
    ans += std::max((double)best, (getmax(1, 0, n-1, l, r) - first) / 2.);
    printf("%.1lf\n", ans);
  }

  return 0;
}

