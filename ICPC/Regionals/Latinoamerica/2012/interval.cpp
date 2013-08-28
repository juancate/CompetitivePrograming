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

int a[maxn], t[4*maxn];

inline int sign(int x) {
  return (x < 0)? -1 : (x > 0)? 1 : 0;
}

void build(int v, int tl, int tr) {
  if(tl == tr) {
    t[v] = a[tl];
  }
  else {
    int tm = (tl + tr) >> 1;
    int next = v << 1;
    build(next, tl, tm);
    build(next+1, tm+1, tr);

    t[v] = t[next] * t[next+1];
  }
}

void update(int v, int tl, int tr, int pos, int new_val) {
  if(tl == tr) {
    t[v] = new_val;
  }
  else {
    int tm = (tl + tr) >> 1;
    int next = v << 1;
    if(pos <= tm)
      update(next, tl, tm, pos, new_val);
    else
      update(next+1, tm+1, tr, pos, new_val);

    t[v] = t[next] * t[next+1];
  }
}

int query(int v, int tl, int tr, int l, int r) {
  if(l > tr || r < tl)
    return 1;

  if(l <= tl && tr <= r)
    return t[v];

  int tm = (tl + tr) >> 1;
  int next = v << 1;

  int left_part = query(next, tl, tm, l, r);
  int right_part = query(next+1, tm+1, tr, l, r);

  return (left_part * right_part);
}

int main() {
#ifdef LOCAL
  freopen("i.in", "r", stdin);
  freopen("i.out", "w", stdout);
#else
  ios_base::sync_with_stdio(false);
#endif

  int n, k;
  while(cin >> n >> k) {
    REP(i, 1, n+1) {
      cin >> a[i];
      a[i] = sign(a[i]);
    }

    build(1, 1, n);
    string ans;

    while(k--) {
      string op; cin >> op;
      if(op == "C") {
        int pos, v;
        cin >> pos >> v;
        update(1, 1, n, pos, sign(v));
      }
      else {
        int l, r;
        cin >> l >> r;
        int ret = query(1, 1, n, l, r);
        ans.push_back((ret < 0)? '-' : (ret > 0)? '+' : '0');
      }
    }
    cout << ans << endl;
  }
}

