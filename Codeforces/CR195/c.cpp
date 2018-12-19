#include <bits/stdc++.h>

using namespace std;

const int maxn = int(1e5);

int n, a[maxn];
vector< vector<int> > ans;
vector<int> ands;

vector<int> get_pos(int mask) {
  vector<int> v;
  for (int i = 0; i < 31; i++)
    if (mask & (1 << i))
      v.push_back(i);
  reverse(v.begin(), v.end());
  return v;
}

int solve() {
  int best = 0, bestv = 0;
  for (int i = 0; i < ans.size(); i++) {
    if (ans[i].empty()) continue;
    for (int j = 0; j < 32; j++) {
      int d = (1 << j);
      if ((ands[i] % d) == 0) {
        if (j > bestv) {
          best = i;
          bestv = j;
        }
        else if (j == bestv && (ans[i].size() > ans[best].size())) {
          best = i;
          bestv = j;
        }
      }
    }
  }
  return best;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  int total = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    total |= a[i];
  }
  sort(a, a+n);
  n = unique(a, a+n)-a;

  vector<int> v = get_pos(total);
  for (int i = 0; i < v.size(); i++) {
    ands.push_back(-1);
    ans.push_back(vector<int>());
    for (int j = 0; j < n; j++) {
      if (a[j] & (1 << v[i])) {
        ans[i].push_back(a[j]);
        ands[i] &= a[j];
      }
    }
  }

  int pos = solve();
  cout << ans[pos].size() << '\n';
  for (int i = 0; i < ans[pos].size(); i++)
    cout << ans[pos][i] << ' ';
  cout << '\n';

  return 0;
}
