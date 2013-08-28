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

struct node {
  int pos, val;

  node(int p = -1, int v = -INF) {
    pos = p;
    val = v;
  }

  bool operator<(const node& b) const {
    return val < b.val;
  }
  bool operator>(const node& b) const {
    return val > b.val;
  }
};

const int maxn = 100010;

int x[maxn], h[maxn], ord[maxn], ans[maxn];
node t[maxn<<2];

void build(int v, int tl, int tr) {
  if(tl == tr)
    t[v] = node(tl);
  else {
    int tm = (tl+tr) >> 1;
    int next = v << 1;
    build(next, tl, tm);
    build(next+1, tm+1, tr);
    t[v] = max(t[next], t[next+1]);
  }
}

void update(int v, int tl, int tr, int pos, node val) {
  if(tl == tr) {
    t[v] = val;
  }
  else {
    int tm = (tl+tr) >> 1;
    int next = v << 1;
    if(pos <= tm)
      update(next, tl, tm, pos, val);
    else
      update(next+1, tm+1, tr, pos, val);

    t[v] = max(t[next], t[next+1]);
  }
}

node query(int v, int tl, int tr, int l, int r) {
  if(l > tr || r < tl)
    return node();
  if(tl >= l && tr <= r)
    return t[v];

  int tm = (tl+tr) >> 1;
  int next = v << 1;

  return max(query(next, tl, tm, l, r), query(next+1, tm+1, tr, l, r));
}

bool cmp(int i, int j) {
  return x[i] < x[j];
}

int search(int v, int n) {
  int lo = 0, hi = n;

  while(lo < hi) {
    int mid = lo + (hi-lo) / 2;
    if(v <= x[ord[mid]]) hi = mid;
    else lo = mid+1;
  }
  return lo;
}

int main() {
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  for(int i = 0; i < n; i++) {
    cin >> x[i] >> h[i];
    ord[i] = i;
    ans[i] = 0;
  }

  sort(ord, ord+n, cmp);
  build(1, 0, n-1);

  for(int i = n-1; i >= 0; i--) {
    int k = ord[i];
    int next = x[k] + h[k] - 1;
    int j = search(next, n);
    int l = ord[j];

    if(x[l] > next || j >= n)
      j--;
    l = ord[j];

    if(j < n-1 && i != j) {
      node curr = query(1, 0, n-1, i, j);
      j = curr.pos;
      l = ord[j];
      ans[k] += ans[l]-1;
    }
    ans[k] += j-i;

    ans[ord[i]]++;
    update(1, 0, n-1, i, node(i, x[k]+h[k]-1));
  }

  for(int i = 0; i < n; i++)
    cout << ans[i] << " ";
  cout << endl;

  return 0;
}

