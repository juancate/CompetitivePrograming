#include <bits/stdc++.h>

using namespace std;

int a[111];
bool cnt[4], exists[4];

string tostr(int x) {
  stringstream ss;
  ss << x;
  return ss.str();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a+n);

  vector<int> ans;
  for (int i = n-1; i >= 0; i--) {
    int l = tostr(a[i]).size();

    if (cnt[l]) continue;
    if (l == 3 && a[i] == 100) {
      ans.push_back(a[i]);
      cnt[l] = true;
    }
    else if (l == 2 && a[i] % 10 == 0) {
      ans.push_back(a[i]);
      cnt[l] = true;
    }
    else if (l == 1 && a[i] == 0) {
      ans.push_back(a[i]);
      cnt[l] = true;
    }
    exists[l] = true;
  }

  for (int i = 0; i < 4; i++)
    if (!exists[i]) cnt[i] = true;

  for (int l = 3; l > 0; l--) {
    if (!cnt[l] || l == 1) {
      for (int i = 0; i < n; i++) {
        int curr = tostr(a[i]).size();
        if (curr == l) {
          if (l == 1 && a[i] == 0) continue;
          bool can = true;
          for (int j = l+1; j < 4; j++)
            can &= cnt[j];
          if (can)
            ans.push_back(a[i]);
          break;
        }
      }
    }
  }

  cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << ' ';
  cout << '\n';

  return 0;
}
