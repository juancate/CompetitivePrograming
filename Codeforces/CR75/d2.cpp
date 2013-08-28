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

const int maxn = int(1e5)+10;

int a[maxn], t[maxn<<2];

void build(int v, int tl, int tr) {
  if(tl == tr) {
    t[v] = a[tl];
  }
  else {
    int tm = (tl+tr) >> 1;
    int next = v << 1;
    build(next, tl, tm);
    build(next+1, tm+1, tr);

    t[v] = min(t[next], t[next+1]);
  }
}

void update(int v, int tl, int tr, int pos, int val) {
  if(tl == tr) {
    t[v] = val;
  }
  else {
    int tm = (tl + tr) >> 1;
    int next = v << 1;

    if(pos <= tm)
      update(next, tl, tm, pos, val);
    else
      update(next+1, tm+1, tr, pos, val);

    t[v] = min(t[next], t[next+1]);
  }
}

int query(int v, int tl, int tr, int l, int r, int val) {
  if(l > tr || r < tl)
    return -1;

  if(t[v] >= val)
    return -1;

  if(tl == tr)
    return tl;

  int tm = (tl+tr) >> 1;
  int next = v << 1;

  int q = query(next+1, tm+1, tr, l, r, val);

  if(q == -1)
    q = query(next, tl, tm, l, r, val);
  return q;
}

int main() {
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  for(int i = 0; i < n; i++)
    cin >> a[i];
  build(1, 0, n-1);

  for(int i = 0; i < n; i++) {
    if(i) cout << " ";

    int ans = query(1, 0, n-1, i+1, n-1, a[i]);
    if(ans == -1)
      cout << ans;
    else
      cout << (ans - i - 1);
  }

  cout << endl;

  return 0;
}

