#include <bits/stdc++.h>

using namespace std;

const long long INF = (long long)(1e18);

const int N = 100010;

int n, k;
long long a[N], sum_upto[N], sum_from[N];

long long solve() {
  long long curr_sum = a[0];
  sum_upto[0] = a[0];
  for (int i = 1; i < n; i++) {
    long long prev_sum = curr_sum;
    curr_sum = max(a[i], prev_sum+a[i]);
    sum_upto[i] = max(curr_sum, sum_upto[i-1]);
  }

  sum_from[n-1] = a[n-1];
  curr_sum = a[n-1];
  for (int i = n-2; i >= 0; i--) {
    long long prev_sum = curr_sum;
    curr_sum = max(a[i], prev_sum+a[i]);
    sum_from[i] = max(curr_sum, sum_from[i+1]);
  }

  long long ans = -INF;

  for (int i = 0; i + k + 1 < n; i++)
    ans = max(ans, sum_upto[i] + sum_from[i+k+1]);

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    cin >> n >> k;
    for (int i = 0; i < n; i++)
      cin >> a[i];

    cout << solve() << '\n';
  }

  return 0;
}
