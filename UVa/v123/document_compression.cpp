#include <bits/stdc++.h>

using namespace std;

const int maxn = 17;

int n, m, doc[111], ans[1<<maxn];

void bfs() {
  queue<int> Q;
  memset(ans, 0, sizeof(ans));

  for (int i = 0; i < m; i++) {
    ans[doc[i]] = 1;
    Q.push(doc[i]);
  }

  while (!Q.empty()) {
    int curr = Q.front();
    Q.pop();

    for (int i = 0; i < m; i++) {
      int next = curr | doc[i];
      if (ans[next] == 0) {
        ans[next] = ans[curr]+1;
        Q.push(next);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> m >> n) {
    if ((n|m) == 0)
      break;

    for (int i = 0, k; i < m; i++) {
      cin >> k;
      doc[i] = 0;
      for (int j = 0, t; j < k; j++) {
        cin >> t;
        doc[i] |= (1 << (t-1));
      }
    }

    bfs();

    for (int i = 0, k, curr; i < n; i++) {
      cin >> k;
      curr = 0;
      for (int j = 0, t; j < k; j++) {
        cin >> t;
        curr |= (1 << (t-1));
      }
      if (i) cout << ' ';
      cout << ans[curr];
    }
    cout << '\n';
  }

  return 0;
}
