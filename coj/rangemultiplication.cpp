#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000009;
const int maxn = 2000100;

int n, m;

struct node {
  int val, mul;
  bool upd;
  node(int v=1, int m=1, bool u=0) :
    val(v), mul(m), upd(u) {}
} t[maxn << 2];

void build(int v, int tl, int tr) {
  if (tl == tr) {
    t[v].val = t[v].mul = 1, t[v].upd = false;
    return;
  }

  int tm = (tl + tr) >> 1;
  int next = v << 1;

  build(next, tl, tm);
  build(next+1, tm+1, tr);

  t[v].val = (t[next].val + t[next+1].val) % mod;
  t[v].mul = 1;
  t[v].upd = false;
}

void set_update(int v, long long k) {
  t[v].upd = true;
  t[v].mul = (t[v].mul * k) % mod;
}

void do_update(int v) {
  if (!t[v].upd) return;

  t[v].val = ((long long)t[v].val * t[v].mul) % mod;

  set_update(v<<1, t[v].mul);
  set_update((v<<1)+1, t[v].mul);

  t[v].mul = 1;
}

void update(int v, int tl, int tr, int l, int r, long long k) {
  if (l <= tl && tr <= r)
    set_update(v, k);
  do_update(v);

  if (l > tr || r < tl)
    return;

  if (!(l <= tl && tr <= r)) {
    int tm = (tl + tr) >> 1;
    int next = v << 1;
    update(next, tl, tm, l, r, k);
    update(next+1, tm+1, tr, l, r, k);

    t[v] = (t[next].val + t[next+1].val) % mod;
  }
}

int query(int v, int tl, int tr, int l, int r) {
  do_update(v);

  if (l > tr || r < tl)
    return 0;

  if (l <= tl && tr <= r)
    return t[v].val;

  int tm = (tl + tr) >> 1;
  int next = v << 1;

  int ans = query(next, tl, tm, l, r) % mod;
  ans = (ans + query(next+1, tm+1, tr, l, r) % mod);

  t[v].val = (t[next].val + t[next+1].val) % mod;

  return ans % mod;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> n >> m) {
    build(1, 1, n);

    for (int i = 0; i < m; i++) {
      int op, l, r;
      cin >> op >> l >> r;
      if (op == 1)
        cout << query(1, 1, n, l, r) << '\n';
      else {
        long long k;
        cin >> k;
        update(1, 1, n, l, r, k);
      }
    }
  }
  cout.flush();

  return 0;
}
