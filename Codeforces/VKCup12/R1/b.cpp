#include <bits/stdc++.h>

using namespace std;

struct item {
  int c, idx;
  item(int c=0, int i=0) :
    c(c), idx(i) {}
  bool operator<(item x) const {
    return c < x.c;
  }
};

const int N = 1010;
vector<int> ans[N];
int cost[N], min_cost[N], type[N];
bool has[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  cin >> n >> k;

  vector<item> s, p;
  for (int i = 0; i < n; i++) {
    int ci, ti;
    cin >> ci >> ti;
    if (ti == 1)
      s.push_back(item(ci, i+1));
    else
      p.push_back(item(ci, i+1));
    cost[i+1] = ci;
    type[i+1] = ti;
  }

  sort(s.rbegin(), s.rend());
  int pos = 0;
  memset(has, 0, sizeof has);
  for (int i = 0, j = 0; i < s.size(); i++, j++, pos++) {
    if (j == k-1)
      break;
    ans[pos].push_back(s[i].idx);
    has[pos] = true;
  }

  for (int i = pos; i < s.size(); i++)
    p.push_back(s[i]);
  sort(p.rbegin(), p.rend());

  for (int i = 0, j = pos % k; i < p.size(); j = (j + 1) % k) {
    if (has[j]) continue;

    ans[j].push_back(p[i++].idx);
  }

  double total_cost = 0;
  for (int i = 0; i < k; i++) {
    min_cost[i] = int(1e9);
    for (int j = 0; j < ans[i].size(); j++) {
      total_cost += cost[ans[i][j]];
      min_cost[i] = min(min_cost[i], cost[ans[i][j]]);
      has[i] |= type[ans[i][j]] == 1;
    }
    if (has[i])
      total_cost -= min_cost[i] * .5;
  }

  cout.precision(1);
  cout.setf(ios::fixed);

  cout << total_cost << '\n';
  for (int i = 0; i < k; i++) {
    cout << ans[i].size();
    for (int j = 0; j < ans[i].size(); j++)
      cout << ' ' << ans[i][j];
    cout << '\n';
  }

  return 0;
}
