#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;

typedef set< pair<int,int>, greater< pair<int,int> > > SET;

int b[maxn];
list<int> g[maxn];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int c, n, a;

  while (cin >> c >> n >> a) {
    for (int i = 0; i < n; i++)
      g[i].clear();

    for (int i = 0, v; i < a; i++) {
      cin >> v;
      b[i] = v;
      g[v].push_back(i);
    }

    int ans = 0;
    SET cache;
    SET::iterator it;

    for (int i = 0; i < a; i++) {
      it = cache.find(make_pair(g[b[i]].front(), b[i]));

      if (it == cache.end()) {
        if (c > 0) c--;
        else cache.erase(cache.begin());
        ans++;
      }
      else
        cache.erase(it);

      g[b[i]].pop_front();
      if (!g[b[i]].empty())
        cache.insert(make_pair(g[b[i]].front(), b[i]));
      else c++;
    }

    cout << ans << '\n';
  }

  return 0;
}
