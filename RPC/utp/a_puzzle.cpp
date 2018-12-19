#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, prod_sz, a[N], p[N], sum[N << 2];

void mul(int d) {
  int carry = 0;
  vector<int> prod;
  for (int i = n-1; i >= 0; i--) {
    int r = (d * d) + carry;
    carry = r / 10;
    prod.push_back(r % 10);
  }
  if (carry)
    prod.push_back(carry);

  reverse(prod.begin(), prod.end());

  prod_sz = prod.size();
  for (int i = 0; i < prod_sz; i++)
    p[i] = prod[i];
}

int solve() {
  int ans = 0;

  int carry = 0;
  int pos = prod_sz-1;
  for (int i = n-1; i >= 0; i--, pos--) {
    int curr = sum[pos] + carry;
    ans += (curr % 10);
    carry = curr / 10;
  }

  for (int i = prod_sz-1; i > 0; i--) {
    int curr = sum[0] - sum[i] + carry;
    ans += (curr % 10);
    carry = curr / 10;
  }
  ans += carry;

  return ans;
}

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int d;

  while (cin >> d >> n) {
    if ((d|n) == 0)
      break;

    for (int i = 0; i < n; i++)
      a[i] = d;

    mul(d);

    memset(sum, 0, sizeof sum);
    for (int i = prod_sz-1; i >= 0; i--)
      sum[i] = p[i] + sum[i+1];

    cout << solve() << '\n';
  }

  return 0;
}
