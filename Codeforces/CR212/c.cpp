#include <bits/stdc++.h>

using namespace std;

const int maxn = 5050;

int n, a[maxn], b[maxn], t[maxn];

int insertion_sort() {
  int total = 0;

  for (int i = 1; i < n; i++) {
    int j = i;
    while (j > 0 && b[j] < b[j-1]) {
      swap(b[j], b[j-1]);
      j = j-1;
      total++;
    }
  }

  return total;
}

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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    a[i] = b[i];
  }

  int total = insertion_sort();
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
      if (curr < ans) {
        ans = curr;
        cnt = 1;
      }
      else if (curr == ans) {
        cnt++;
      }
    }
  }

  cout << ans << ' ' << cnt << '\n';

  return 0;
}
