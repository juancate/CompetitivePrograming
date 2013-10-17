#include <bits/stdc++.h>

#define foreach(it,v) \
  for (__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)

using namespace std;

int n, cnt[5];

int solve() {
  int ans = 0;

  if (cnt[1] <= cnt[2]) {
    ans += cnt[1];
    cnt[2] -= cnt[1];
    ans += min(cnt[2], cnt[4]);
    cnt[2] -= min(cnt[2], cnt[4]);

    if (cnt[2] > 0)
      return -1;
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0, a; i < n; i++) {
    cin >> a;
    cnt[a]++;
  }

  cout << solve() << '\n';

  return 0;
}

