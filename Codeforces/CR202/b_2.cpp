#include <bits/stdc++.h>

using namespace std;

struct digit {
  int paint, id;

  digit(int p=0, int id=-1) : paint(p), id(id) {}

  bool operator<(const digit& d) const {
    if (paint == d.paint)
      return id > d.id;
    return paint < d.paint;
  }
} a[10];

int v;
string memo[9][1000010];

string solve(int i, int vv) {
  if (i == 9)
    return "";
  if (memo[i][vv] != "0")
    return memo[i][vv];

  string r = "0";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> v;
  for (int i = 0; i < 9; i++) {
    cin >> a[i].paint;
    a[i].id = i+1;
  }
  sort(a, a+9);
  for (int i = 0; i < 9; i++)
    cerr << "(" << a[i].paint << ", " << a[i].id << ") ";
  cerr << '\n';

  int best = -int(1e9);
  int d = 0;
  for (int i = 0; i < 9; i++) {
    int curr = v / a[i].paint;
    if (curr > best) {
      d = i;
      best = curr;
    }
    else if (curr == best && a[i].id > a[d].id) {
      d = i;
    }
  }

  bool painted = false;
  string ans;
  while (v - a[d].paint >= 0) {
    ans.push_back(a[d].id + '0');
    v -= a[d].paint;
    painted = true;
  }

  if (v > 0) {
    int pos = lower_bound(a, a+9, v) - a;
    if (a[pos].paint == v) {
      if (a[pos].id > a[d].id)
        ans = char(a[pos].id + '0') + ans;
      else
        ans += (a[pos].id + '0');
      painted = true;
    }
  }

  if (!painted) cout << "-1\n";
  else cout << ans << '\n';

  return 0;
}
