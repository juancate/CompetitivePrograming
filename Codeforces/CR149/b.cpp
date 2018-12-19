#include <bits/stdc++.h>

using namespace std;

struct interval {
  int L, R, index;
  interval(int L=0, int R=0, int i=-1) :
    L(L), R(R), index(i) {}
  bool operator<(const interval& o) const {
    if (L == o.L)
      return R < o.R;
    return L < o.L;
  }
};

const int maxn = int(1e5)+10;

int n;
interval seg[maxn];

int solve(int best) {
  int start = seg[best].L;
  int end = seg[best].R;

  for (int i = 0; i < n; i++) {
    if (!(start <= seg[i].L && seg[i].R <= end))
      return -1;
  }
  return seg[best].index;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> seg[i].L >> seg[i].R;
    seg[i].index = i+1;
  }
  sort(seg, seg+n);

  int start = seg[0].L;
  int end = seg[0].R;
  int best = 0;
  for (int i = 1; i < n; i++) {
    if (seg[i].L > start)
      break;
    if (seg[i].R > end) {
      best = i;
      end = seg[i].R;
    }
  }
  cout << solve(best) << '\n';
  return 0;
}
