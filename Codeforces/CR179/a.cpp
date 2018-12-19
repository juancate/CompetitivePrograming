#include <bits/stdc++.h>

using namespace std;

const int maxn = 111;

int n, a[maxn], cnt[1111];

bool solve() {
  for (int i = 1; i <= 1000; i++) {
    if (cnt[i]-1 > n-cnt[i])
      return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }

  if (solve())
    cout << "YES\n";
  else
    cout << "NO\n";

  return 0;
}
