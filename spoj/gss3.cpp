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

const int maxn = 50010;

struct node {
  int val;
  bool left, right;

  node(int v = 0, int l = true, int r = true) {
    val = v;
    left = l;
    right = r;
  }
} t[maxn<<2];

int a[maxn];

node get_max(const node& l, const node& r) {
  node n;
  if(l.left && !l.right) {
    if(l.val > r.val)
      n = node(l.val, true, false);
    else
      n = node(r.val, false, true);
  }
  else if((!l.left && l.right) ||
          (l.left && l.right)) {
    if((r.left && r.right) || r.left) {
      int val = l.val + r.val;

      if(val > l.val && val > r.val) {
        n = node(val);
      }
      else {
        if(l.val > r.val)
          n = node(l.val, true, false);
        else
          n = node(r.val, false, true);
      }
    }
    else if(!r.left && r.right) {
      if(l.val > r.val)
        n = node(l.val, true, false);
      else
        n = node(r.val, false, true);
    }
  }

  return n;
}

void build(int v, int tl, int tr) {
  if(tl == tr) {
    t[v] = node(a[tl]);
  }
  else {
    int tm = (tl+tr) >> 1;
    int next = v << 1;

    build(next, tl, tm);
    build(next+1, tm+1, tr);

    t[v] = get_max(t[next], t[next+1]);
  }
}

void update(int v, int tl, int tr, int pos, int val) {
  if(tl == tr) {
    t[v] = node(val);
  }
  else {
    int tm = (tl+tr) >> 1;
    int next = v << 1;

    if(pos <= tm)
      update(next, tl, tm, pos, val);
    else
      update(next+1, tm+1, tr, pos, val);

    t[v] = get_max(t[next], t[next+1]);
  }
}

node query(int v, int tl, int tr, int l, int r) {
  if(l > tr || r < tl)
    return node(-INF);
  if(tl >= l && tr <= r)
    return t[v];

  int tm = (tl+tr) >> 1;
  int next = v << 1;

  node ls = query(next, tl, tm, l, r);
  node rs = query(next+1, tm+1, tr, l, r);

  return get_max(ls, rs);
}

int main() {
  int n, m;
  scanf("%d", &n);

  for(int i = 1; i <= n; i++)
    scanf("%d", &a[i]);

  build(1, 1, n);

  scanf("%d", &m);

  while(m--) {
    int op;
    scanf("%d", &op);

    if(op == 0) {
      int pos, val;
      scanf("%d%d", &pos, &val);
      update(1, 1, n, pos, val);
    }
    else {
      int l, r;
      scanf("%d%d", &l, &r);
      node x = query(1, 1, n, l, r);
      printf("%d\n", x.val);
    }
  }

  return 0;
}

