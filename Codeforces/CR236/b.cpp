#include <bits/stdc++.h>

using namespace std;

const int INF = int(1e9);
const int N = 1010;

int n, k, a[N], b[N], ans[N];

int solve(int i) {
  int prev = i;
  b[i] = a[i];

  int changes = 0;
  for (int j = i+1; j < n; j++) {
    b[j] = a[j];
    if (a[j] - b[prev] != k) {
      b[j] = b[prev] + k;
      changes++;
    }
    prev = j;
  }

  prev = i;
  for (int j = i-1; j >= 0; j--) {
    b[j] = a[j];
    if (b[prev] - a[j] != k) {
      b[j] = b[prev] - k;
      if (b[j] <= 0)
        return INF;
      changes++;
    }
    prev = j;
  }

  return changes;
}

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k;

  for (int i = 0; i < n; i++)
    cin >> a[i];

  int best = N;
  for (int i = 0; i < n; i++) {
    int curr = solve(i);
    if (curr < best) {
      best = curr;
      for (int j = 0; j < n; j++)
        ans[j] = b[j];
    }
  }

  cout << best << '\n';
  for (int i = 0; i < n; i++) {
    if (ans[i] != a[i]) {
      if (ans[i] < a[i])
        cout << "- ";
      else
        cout << "+ ";
      cout << i+1 << ' ' << abs(ans[i]-a[i]) << '\n';
    }
  }

  return 0;
}
