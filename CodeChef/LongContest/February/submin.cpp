#include <bits/stdc++.h>

using namespace std;

const int INF = int(1e9);

const int N = 55;

int a[N], t[N << 2];

void build(int v, int tl, int tr) {
  if (tl == tr)
    t[v] = a[tl];
  else {
    int tm = (tr + tl) >> 1;
    int next = v << 1;

    build(next, tl, tm);
    build(next+1, tm+1, tr);

    t[v] = min(t[next], t[next+1]);
  }
}

int get(int v, int tl, int tr, int l, int r) {
  if (l > tr || r < tl)
    return INF;

  if (l <= tl && tr <= r)
    return t[v];

  int tm = (tr + tl) >> 1;
  int next = v << 1;

  int left = get(next, tl, tm, l, r);
  int right = get(next+1, tm+1, tr, l, r);

  return min(left, right);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, q, k;
  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> a[i];
  build(1, 0, n-1);

  cin >> q;
  while (q--) {
    cin >> k;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        int v = get(1, 0, n-1, i, j);
        if (v == k)
          ans++;
      }
    }
    cout << ans << '\n';
  }

  return 0;
}
