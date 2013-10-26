#include <bits/stdc++.h>

#define foreach(it,v) \
  for (__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)

using namespace std;

const int maxn = 1010;

int n, a[maxn];

bool solve() {
  for (int i = 0; i < n-1; i++) {
    for (int j = 0; j < i; j++) {
      if ((a[i] < a[j] && a[j] < a[i+1]) || (a[i+1] < a[j] && a[j] < a[i])) {
        int l = a[j];
        int r = a[j+1];
        if (l > r)
          swap(l, r);
        if ((l < a[i] && a[i] < r) || (l < a[i+1] && a[i+1] < r))
          return true;

        if (j > 0) {
          l = a[j-1];
          r = a[j];
          if (l > r)
            swap(l, r);
          if ((l < a[i] && a[i] < r) || (l < a[i+1] && a[i+1] < r))
            return true;
        }
      }
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  cout << (solve()? "yes" : "no") << '\n';

  return 0;
}

