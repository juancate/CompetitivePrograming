#include <bits/stdc++.h>

using namespace std;

const int N = 111;

int a[N], b[N], c[N], d[N];
bool seen[N];

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  while (cin >> n) {
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      d[a[i]] = i;
    }

    for (int i = 0; i < n; i++) {
      cin >> b[i];
      c[b[i]] = i;
    }

    memset(seen, 0, sizeof seen);

    int ans = 0, best = -1;
    for (int i = 0; i < n; i++) {
      if (!seen[a[i]]) {
        int curr = i, cnt = 0;
        while (!seen[a[curr]]) {
          seen[a[curr]] = true;

          if (a[curr] == b[curr]) break;

          int next = c[a[curr]];
          curr = d[a[next]];
          cnt++;
        }

        if (cnt == 0) continue;

        ans++;
        best = max(best, cnt);
      }
    }

    cout << ans << ' ' << best << '\n';
  }

  return 0;
}
