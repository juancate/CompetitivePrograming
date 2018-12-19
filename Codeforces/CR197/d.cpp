#include <bits/stdc++.h>

using namespace std;

const int maxn = int(2e5)+10;

bool odd;
int a[maxn];

struct node {
  int v, d;
  node(int u=0, int _d=0) :
    v(u), d(_d) {}
} t[maxn<<2];

void build(int v, int tl, int tr) {
  if(tl == tr) {
    t[v] = node(a[tl]);
  }
  else {
    int tm = (tl + tr) >> 1;
    int next = v << 1;
    build(next, tl, tm);
    build(next+1, tm+1, tr);

    t[v].d = t[next].d+1;
    if (t[v].d & 1)
      t[v].v = t[next].v | t[next+1].v;
    else
      t[v].v = t[next].v ^ t[next+1].v;
  }
}

void update(int v, int tl, int tr, int pos, int new_val) {
  if(tl == tr) {
    t[v] = node(new_val);
  }
  else {
    int tm = (tl + tr) >> 1;
    int next = v << 1;
    if(pos <= tm)
      update(next, tl, tm, pos, new_val);
    else
      update(next+1, tm+1, tr, pos, new_val);

    if (t[v].d & 1)
      t[v].v = t[next].v | t[next+1].v;
    else
      t[v].v = t[next].v ^ t[next+1].v;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  n = 1 << n;

  for (int i = 0; i < n; i++)
    cin >> a[i];
  build(1, 0, n-1);

  for (int i = 0; i < m; i++) {
    int p, b;
    cin >> p >> b;

    update(1, 0, n-1, p-1, b);
    cout << t[1].v << '\n';
  }

  return 0;
}
