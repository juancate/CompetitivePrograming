#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;

struct order {
  int a, b, id;
  order(int _a=0, int _b=0) {
    a = _a;
    b = _b;
  }
} a[maxn];

bool cmp(const order& o1, const order& o2) {
  if (o1.a == o2.a)
    return o1.b < o2.b;
  return o1.a > o2.a;
}

int n, p, k;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> p >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i].a >> a[i].b;
    a[i].id = i+1;
  }

  vector<int> ans;
  sort(a, a+n, cmp);

  for (int i = 0, j = 0; i < n && j < p; i++) {
    ans.push_back(a[i].id);
    j++;
  }

  assert(ans.size() == p);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << ' ';
  cout << endl;

  return 0;
}
