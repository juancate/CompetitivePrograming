#include <bits/stdc++.h>

#define foreach(it,v) \
  for (__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)

using namespace std;

const int maxn = 300010;

int p[maxn];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;
  set<int> s;
  for (int i = 1; i <= n; i++)
    s.insert(i);

  for (int i = 0; i < m; i++) {
    int l, r, x;
    cin >> l >> r >> x;
    set<int>::iterator itl, itr, itc;
    itl = s.lower_bound(l);
    itr = s.upper_bound(r);

    for (itc = itl; itc != itr; itc++) {
      int v = *itc;
      if (v != x)
        p[v] = x;
    }
    s.erase(itl, itr);
    s.insert(x);
  }

  for (int i = 1; i <= n; i++)
    cout << p[i] << ' ';
  cout << '\n';

  return 0;
}

