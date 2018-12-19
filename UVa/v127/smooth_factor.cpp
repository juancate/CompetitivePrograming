#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, a[N], cnt[N];

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> n) {
    for (int i = 0; i < n; i++) {
      cin >> a[i];

      cnt[i] = 0;
      if (i > 0)
        cnt[i] = cnt[i-1] + (a[i-1] > a[i]);
    }

    int best = 0;

    for (int i = 0, j = 0; i < n; i++) {
      while (j < n && cnt[j] - cnt[i] <= 1)
        j++;
      best = max(best, j-i);
    }

    cout << best << '\n';
  }

  return 0;
}
