#include <bits/stdc++.h>

#define foreach(it,v) \
  for (__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)

using namespace std;

const int maxn = 100010;

int n, a[maxn];
map< int, vector<int> > M;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    M[a[i]].push_back(i);
  }

  vector< pair<int,int> > ans;
  foreach(it, M) {
    int key = it->first;
    vector<int> & seq = it->second;

    int diff = 0;
    bool valid = true;
    for (int i = 1; i < seq.size(); i++) {
      if (i == 1) diff = seq[i] - seq[i-1];
      else {
        if (seq[i] - seq[i-1] != diff)
          valid = false;
      }
    }

    if (valid)
      ans.push_back(make_pair(key, diff));
  }

  cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i].first << ' ' << ans[i].second << '\n';

  return 0;
}

