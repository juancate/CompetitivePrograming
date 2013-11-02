#include <bits/stdc++.h>

using namespace std;

// TLE!!

const int maxn = 555;

int n, m, a[maxn][maxn], b[maxn][2];
bool valid_int[maxn];

void calc_intervals(int L, int U) {
  for (int i = 0; i < n; i++) {
    int l = lower_bound(a[i], a[i]+m, L) - a[i];
    int r = upper_bound(a[i], a[i]+m, U) - a[i] - 1;

    if (l > r)
      valid_int[i] = false;
    b[i][0] = l;
    b[i][1] = r;
  }
}

bool intersect(int l1, int r1, int l2, int r2, int & nl, int & nr) {
  if (l2 > r1 || r2 < l1)
    return false;

  nl = max(l1, l2);
  nr = min(r1, r2);
  return true;
}

int solve(int L, int U) {
  memset(valid_int, 1, sizeof valid_int);
  calc_intervals(L, U);

  int best = 0;
  for (int i = 0; i < n; i++) {
    if (!valid_int[i]) continue;

    int h = 0;
    int l = b[i][0];
    int r = b[i][1];
    for (int j = i; j < n; j++) {
      if (!valid_int[j])
        break;
      if (intersect(l, r, b[j][0], b[j][1], l, r)) {
        h++;
        best = max(best, min(h, r-l+1));
      }
      else {
        h = 1;
        l = b[j][0];
        r = b[j][1];
        best = max(best, min(h, r-l+1));
      }
    }
  }

  return best;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> n >> m) {
    if ((n|m) == 0)
      break;

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> a[i][j];

    int Q, L, U;

    cin >> Q;
    while (Q--) {
      cin >> L >> U;
      cout << solve(L, U) << '\n';
    }
    cout << "-\n";
  }

  return 0;
}
