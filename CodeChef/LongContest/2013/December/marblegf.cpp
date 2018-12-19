#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int n, q;
long long t[N];

void update(int k, int v) {
  for (; k <= n; k += (k & -k))
    t[k] += v;
}

long long get(int k) {
  long long sum = 0;
  for (; k; k -= (k & -k))
    sum += t[k];
  return sum;
}

long long get_range(int a, int b) {
  return get(b) - (a <= 1? 0 : get(a-1));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> q;
  for (int i = 1, x; i <= n; i++) {
    cin >> x;
    update(i, x);
  }

  while (q--) {
    char op;
    int a, b;
    cin >> op >> a >> b;
    a++;

    if (op == 'S')
      cout << get_range(a, b+1) << '\n';
    else
      update(a, (op == 'T' ? -b : b));
  }

  return 0;
}
