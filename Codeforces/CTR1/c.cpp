#include <bits/stdc++.h>

using namespace std;

const long long INF = (long long)(1e18);
const int maxn = 300010;

int n, a[maxn];

struct node {
  long long val, sum;
  bool upd;
  node(long long v=0, long long s=0, bool u=0) :
    val(v), sum(s), upd(u) {}
} t[maxn << 2];

void build(int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = node(a[tl]);
    return;
  }

  int tm = (tl+tr) >> 1;
  int next = v << 1;

  build(next, tl, tm);
  build(next+1, tm+1, tr);

  t[v] = node(min(t[next].val, t[next+1].val));
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

    t[v].val = min(t[next].val, t[next+1].val);
  }
}

long long query(int v, int tl, int tr, int l, int r) {
  do_update(v);

  if (l > tr || r < tl)
    return INF;

  if (l <= tl && tr <= r)
    return t[v].val;

  int tm = (tl+tr) >> 1;
  int next = v << 1;

  long long left_part = query(next, tl, tm, l, r);
  long long right_part = query(next+1, tm+1, tr, l, r);

  return min(left_part, right_part);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string ln;
  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> a[i];

  build(1, 0, n-1);

  int q;
  cin >> q;

  cin.get();
  while (q--) {
    getline(cin, ln);
    int l, r, v;

    if (sscanf(ln.c_str(), "%d%d%d", &l, &r, &v) == 3) {
      if (r < l) {
        update(1, 0, n-1, l, n-1, v);
        update(1, 0, n-1, 0, r, v);
      }
      else {
        update(1, 0, n-1, l, r, v);
      }
    }
    else {
      long long ans = INF;

      if (r < l)
        ans = min(query(1, 0, n-1, l, n-1), query(1, 0, n-1, 0, r));
      else
        ans = query(1, 0, n-1, l, r);
      cout << ans << '\n';
    }
  }

  return 0;
}
