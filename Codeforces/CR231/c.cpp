#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n, m, rows[N];
map<string,int> cnt;
int ans[N][N];
const string d[] = {"00", "11", "10", "01"};

struct item {
  int c, l, r;
  item(int c=0, int l=0, int r=0) :
    c(c), l(l), r(r) {}

  bool operator<(const item & o) const {
    int a = min(l, r);
    int b = min(o.l, o.r);

    if (a == b) {
      int c1 = c;
      int c2 = o.c;

      if (rows[c1] >= n)
        return false;

      if (rows[c2] >= n)
        return true;

      return c < o.c;
    }

    return a < b;
  }
};

void solve() {
  memset(ans, 0, sizeof ans);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      if (cnt["11"] > 0) {
        ans[i][j] = 1;
        cnt["11"]--;
      }
  }

  set<item> pq;
  for (int j = 0; j < m; j++) {
    int r = 0;
    while (r < n && ans[r][j] == 1)
      r++;
    rows[j] = r;
    pq.insert(item(j, r, r));
  }

  while (cnt["01"] > 0) {
    item next = *pq.begin();
    pq.erase(pq.begin());

    int c = next.c;
    if (next.r < next.l) {
      ans[rows[c]][c] = 3;
      next.r++;
    }
    else {
      ans[rows[c]][c] = 2;
      next.l++;
    }
    rows[c]++;
    pq.insert(next);
    cnt["01"]--;
  }

  for (int i = 0; i < n; i++) {
    cout << d[ans[i][0]];
    for (int j = 1; j < m; j++)
      cout << ' ' << d[ans[i][j]];
    cout << '\n';
  }
}

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      string s;
      cin >> s;
      sort(s.begin(), s.end());
      cnt[s]++;
    }
  }

  solve();

  return 0;
}
