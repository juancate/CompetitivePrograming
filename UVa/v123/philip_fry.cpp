#include <bits/stdc++.h>

using namespace std;

class BIT {
public:
  int t[111], n;
  BIT(int m) {
    n = ++m;
    fill(t, t+n, 0);
  }

  int rsq(int idx) {
    int sum = 0;
    for (; idx; idx -= (idx & -idx))
      sum += t[idx];
    return sum;
  }

  int rsq(int a, int b) {
    return rsq(b) - (a == 1 ? 0 : rsq(a-1));
  }

  void adjust(int k, int v) {
    for (; k <= n; k += (k & -k))
      t[k] += v;
  }
};

int main() {
  int n;
  while (scanf("%d", &n)) {
    if (n == 0)
      break;

    BIT tree(n);
    priority_queue< pair<int,int> > Q;

    for (int i = 0, t, s; i < n; i++) {
      scanf("%d%d", &t, &s);
      Q.push(make_pair(t, i+1));
      tree.adjust(i+2, s);
    }

    int ans = 0;

    while (!Q.empty()) {
      int t = Q.top().first;
      int i = Q.top().second;
      Q.pop();
      int curr = tree.rsq(1, i);
      if (curr > 0) {
        int j = i-1;
        while (curr == tree.rsq(1, j)) j--;
        tree.adjust(j+1, -1);
        t >>= 1;
      }
      ans += t;
    }

    printf("%d\n", ans);
  }

  return 0;
}
