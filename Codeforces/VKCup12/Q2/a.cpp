#include <bits/stdc++.h>

#define foreach(it,v) for (__typeof((v).begin()) it=(v).begin(); it != (v).end(); it++)

using namespace std;

const int maxn = 1001;

int n, d, v[maxn];
string a[maxn], b[maxn];
set< pair<string, string> > ans;

bool solve(int index) {
  string A = a[index];
  string B = b[index];

  for (int i = index+1; i < n; i++)
    if (a[i] == B && b[i] == A) {
      int diff = v[i] - v[index];
      if (0 < diff && diff <= d)
        return true;
    }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> d;
  for (int i = 0; i < n; i++)
    cin >> a[i] >> b[i] >> v[i];

  for (int i = 0; i < n; i++) {
    if (solve(i)) {
      vector<string> curr(2);
      curr[0] = a[i], curr[1] = b[i];
      sort(curr.begin(), curr.end());
      ans.insert(make_pair(curr[0], curr[1]));
    }
  }

  cout << ans.size() << endl;
  foreach (i, ans)
    cout << i->first << ' ' << i->second << '\n';

  return 0;
}
