#include <bits/stdc++.h>

using namespace std;

const int maxn = 5050;

int n, a[maxn], b[maxn], c[maxn], t[maxn];

void insert(int i, int v = 1) {
  for (; i <= n; i += (i & -i))
    t[i] += v;
}

int get(int i) {
  int r = 0;
  for (; i; i -= (i & -i))
    r += t[i];
  return r;
}

int get_r(int i, int j) {
  return get(j) - (i == 1? 0 : get(i-1));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    a[i] = b[i];
  }
  sort(b, b+n);

  for (int i = 0; i < n; i++)
    c[b[i]] = i+1;

  int total = 0;
  memset(t, 0, sizeof t);

  for (int i = 0; i < n; i++) {
    int pos = c[a[i]];
    total += get_r(pos+1, n);
    insert(pos);
  }

  int ans = int(1e9), cnt = 0;

  for (int i = 0; i < n; i++) {
    memset(t, 0, sizeof t);
    insert(a[i]+1);

    for (int j = i+1; j < n; j++) {
      insert(a[j]+1);
      int d = j-i;
      int x = get(a[i]);
      int y = get(a[j]);

      int curr = total - x + (d - x) + y - (d - y) + 1;

      if (curr == ans)
        cnt++;
      else if (curr < ans) {
        ans = curr;
        cnt = 1;
      }
    }
  }

  cout << ans << ' ' << cnt << '\n';

  return 0;
}
