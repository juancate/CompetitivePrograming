#include <bits/stdc++.h>

using namespace std;

const long long INF = (long long)(1e18);

const int maxn = 50010;

int a[maxn];

struct node {
  long long sum, prefix, suffix, best;
  node(long long s=0, long long p=0, long long suf=0, long long b=0) :
    sum(s), prefix(p), suffix(suf), best(b) {}
} t[maxn << 2];

node join(const node& l, const node& r) {
  node n;
  n.sum = l.sum + r.sum;
  n.prefix = max(l.prefix, l.sum + r.prefix);
  n.suffix = max(r.suffix, r.sum + l.suffix);
  n.best = max(l.suffix + r.prefix, max(l.best, r.best));

  return n;
}

void build(int v, int tl, int tr) {
  if (tl == tr)
    t[v] = node(a[tl], a[tl], a[tl], a[tl]);
  else {
    int tm = (tl + tr) >> 1;
    int next = v << 1;

    build(next, tl, tm);
    build(next+1, tm+1, tr);

    t[v] = join(t[next], t[next+1]);
  }
}

void update(int v, int tl, int tr, int pos, int val) {
  if (tl == tr)
    t[v] = node(val, val, val, val);
  else {
    int tm = (tl + tr) >> 1;
    int next = v << 1;

    if (pos <= tm)
      update(next, tl, tm, pos, val);
    else
      update(next+1, tm+1, tr, pos, val);

    t[v] = join(t[next], t[next+1]);
  }
}

node query(int v, int tl, int tr, int l, int r) {
  if (tr < l || tl > r)
    return node(-INF, -INF, -INF, -INF);

  if (l <= tl && tr <= r)
    return t[v];

  int tm = (tl + tr) >> 1;
  int next = v << 1;

  node left = query(next, tl, tm, l, r);
  node right = query(next+1, tm+1, tr, l, r);

  if (left.sum == -INF)
    return right;
  if (right.sum == -INF)
    return left;

  return join(left, right);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++)
    cin >> a[i];

  build(1, 1, n);

  int m;
  cin >> m;

  while (m--) {
    int l, r;
    cin >> l >> r;

    node ans = query(1, 1, n, l, r);
    cout << ans.best << '\n';
  }

  return 0;
}
