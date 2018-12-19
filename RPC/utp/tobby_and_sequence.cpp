#include <bits/stdc++.h>

using namespace std;

const int INF = int(1e9);

int a[1010];

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  while (cin >> n) {
    int h = INF-1, l = 1;
    for (int i = 0; i < n; i += 2) {
      a[i] = h;
      a[i+1] = l;
      h--, l++;
    }

    for (int i = 0; i < n; i++) {
      if (i) cout << ' ';
      cout << a[i];
    }
    cout << '\n';
  }

  return 0;
}
