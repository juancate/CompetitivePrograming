#include <bits/stdc++.h>

using namespace std;

const long long INF = (long long)(1e18);
const int maxn = 200010;

struct node {
  long long sum;
  int id;

  node(long long s = 0, int i = -1) {
    sum = s;
    id = i;
  }

  bool operator>(const node& b) const {
    if (sum == b.sum)
      return id < b.id;
    return sum > b.sum;
  }

  bool operator<(const node& b) const {
    if (sum == b.sum)
      return id > b.id;
    return sum < b.sum;
  }
} t[maxn << 2];

long long a[maxn], b[maxn];
int n, k;

void build(int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = node(a[tl], tl);
  }
  else {
    int tm = (tl + tr) >> 1;
    int next = v << 1;
    build(next, tl, tm);
    build(next+1, tm+1, tr);

    t[v] = max(t[next], t[next+1]);
  }
}

node query(int v, int tl, int tr, int l, int r) {
  if (l > tr || r < tl)
    return node(-INF, int(1e9));

  if (l <= tl && tr <= r)
    return t[v];

  int tm = (tl + tr) >> 1;
  int next = v << 1;

  node left_max = query(next, tl, tm, l, r);
  node right_max = query(next+1, tm+1, tr, l, r);

  return max(left_max, right_max);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    cin >> b[i];
    if (i > 0) b[i] += b[i-1];
    a[i] = -INF;
  }

  for (int i = 0; i+k-1 < n; i++) {
    a[i] = b[i+k-1];
    if (i > 0) a[i] -= b[i-1];
  }

  build(1, 0, n);
  int aa, bb;
  long long best = -INF;

  for (int i = 0; i+k+k-1 < n; i++) {
    node m = query(1, 0, n, i+k, n);
    long long curr = a[i] + m.sum;
    if (curr > best) {
      aa = i+1;
      bb = m.id+1;
      best = curr;
    }
  }

  cout << aa << " " << bb << endl;

  return 0;
}
