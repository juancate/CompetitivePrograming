#include <bits/stdc++.h>

using namespace std;

const long long INF = (long long)1e18;
const int maxn = 100010;

int n, a[maxn];

struct node {
  long long val, sum;
  int pos;
  bool upd;
  node(long long v=0, int pos=-1, long long s=0, bool u=0) :
    val(v), pos(pos), sum(s), upd(u) {}
} t[maxn << 2];

void build(int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = node(a[tl], tl);
    return;
  }

  int tm = (tl+tr) >> 1;
  int next = v << 1;

  build(next, tl, tm);
  build(next+1, tm+1, tr);

  if (t[next].val < t[next+1].val)
    t[v] = node(t[next].val, t[next].pos);
  else
    t[v] = node(t[next+1].val, t[next+1].pos);
}

void set_update(int v, long long k) {
  t[v].upd = true;
  t[v].sum += k;
}

void do_update(int v) {
  if (!t[v].upd) return;

  t[v].val += t[v].sum;

  set_update(v << 1, t[v].sum);
  set_update((v << 1)+1, t[v].sum);

  t[v].sum = 0;
  t[v].upd = false;
}

void update(int v, int tl, int tr, int l, int r, long long k) {
  if (l <= tl && tr <= r)
    set_update(v, k);
  do_update(v);

  if (l > tr || r < tl)
    return;

  if (!(l <= tl && tr <= r)) {
    int tm = (tl+tr) >> 1;
    int next = v << 1;

    update(next, tl, tm, l, r, k);
    update(next+1, tm+1, tr, l, r, k);

    if (t[next].val < t[next+1].val)
      t[v] = node(t[next].val, t[next].pos);
    else
      t[v] = node(t[next+1].val, t[next+1].pos);
  }
}

pair<long long, int> query(int v, int tl, int tr, int l, int r) {
  do_update(v);

  if (l > tr || r < tl)
    return make_pair(INF, -1);

  if (l <= tl && tr <= r)
    return make_pair(t[v].val, t[v].pos);

  int tm = (tl+tr) >> 1;
  int next = v << 1;

  pair<long long, int> left_part = query(next, tl, tm, l, r);
  pair<long long, int> right_part = query(next+1, tm+1, tr, l, r);

  return min(left_part, right_part);
}

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int m, w;
  cin >> n >> m >> w;

  for (int i = 0; i < n; i++)
    cin >> a[i];
  build(1, 0, n-1);

  while (m--) {
    pair<long long, int> x = query(1, 0, n-1, 0, n-1);
    pair<long long, int> l = query(1, 0, n-1, max(0, x.second-w+1), x.second-1);
    pair<long long, int> r = query(1, 0, n-1, x.second+1, min(n-1, x.second+w-1));

    //cerr << "x: " << x.first << "#" << x.second << '\n';
    //cerr << "l: " << l.first << "#" << l.second << '\n';
    //cerr << "r: " << r.first << "#" << r.second << '\n';
    int tl = x.second, tr = x.second;
    if (l.first < r.first && l.second >= 0) {
      tl = l.second, tr = min(tl + w, n-1);
      if (tr - tl < w) {
        int d = tr - tl;
        tl = max(0, tl-d);
        d = tr - tl;
        if (d < w)
          tr = min(tr + d, n-1);
      }
    }
    else if (r.second >= 0) {
      tl = max(0, r.second-w), tr = r.second;
      if (tr - tl < w) {
        int d = tr - tl;
        tr = min(tr + d, n-1);
        d = tr - tl;
        if (d < w)
          tl = max(0, tl-d);
      }
    }

    //cerr << "tl,tr: " << tl << "," << tr << '\n';
    update(1, 0, n-1, tl, tr, 1);
  }

  pair<long long, int> ans = query(1, 0, n-1, 0, n-1);
  cout << ans.first << '\n';

  return 0;
}

