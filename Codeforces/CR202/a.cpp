#include <bits/stdc++.h>

using namespace std;

const int maxn = int(1e5)+10;

int n, a[maxn], cnt[111];

bool solve() {
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < n; i++) {
    if (a[i] == 50) {
      if (cnt[25] > 0) {
        cnt[25]--;
      }
      else return false;
    }
    if (a[i] == 100) {
      if (cnt[50] > 0 && cnt[25] > 0) {
        cnt[50]--, cnt[25]--;
      }
      else if (cnt[25] >= 3) {
        cnt[25] -= 3;
      }
      else return false;
    }
    cnt[a[i]]++;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  cout << (solve()? "YES" : "NO") << '\n';

  return 0;
}
