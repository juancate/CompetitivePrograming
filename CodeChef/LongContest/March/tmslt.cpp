#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;
const int mod = 1000000;

int counting_sort[N], m[N], num[N];
long long sum[2];

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    long long prev = d;
    memset(counting_sort, 0, sizeof counting_sort);
    counting_sort[d]++;

    int max_num = d;
    for (int i = 1; i < n; i++) {
      int next = (a * prev * prev + b * prev + c) % mod;

      max_num = max(max_num, next);
      counting_sort[next]++;

      prev = next;
    }

    int pos = 0;
    for (int i = 0; i <= max_num; i++) {
      if (counting_sort[i] > 0) {
        m[pos] = counting_sort[i];
        num[pos++] = i;
      }
    }

    sum[0] = sum[1] = 0;
    int team = 0;
    pos--;
    while (pos >= 0) {
      sum[team] += num[pos];
      m[pos]--;
      team ^= 1;

      if (m[pos] == 0)
        pos--;
    }

    cout << (sum[0] - sum[1]) << '\n';
  }

  return 0;
}
