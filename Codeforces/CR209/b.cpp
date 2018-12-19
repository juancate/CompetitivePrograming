#include <bits/stdc++.h>

#define foreach(it,v) \
  for (__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)

using namespace std;

const int maxn = 100010;

int a[maxn];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  cin >> n >> k;

  for (int i = 1; i <= 2*n; i++)
    a[i] = i;

  for (int i = 1; i <= k; i++)
    swap(a[2*i-1], a[2*i]);

  for (int i = 1; i <= 2*n; i++)
    cout << a[i] << ' ';
  cout << '\n';

  return 0;
}

