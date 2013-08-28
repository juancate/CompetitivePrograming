#include <bits/stdc++.h>

using namespace std;

int a[2010];

int main() {
  int n, d;
  scanf("%d%d", &n, &d);

  for (int i = 0; i < n; i++)
    scanf("%d", a+i);

  int moves = 0;

  for (int i = 1; i < n; i++) {
    if (a[i] <= a[i-1]) {
      int x = (a[i-1]-a[i]+d) / d;
      a[i] += x * d;
      moves += x;
      assert(a[i-1] < a[i]);
    }
  }

  cout << moves << endl;

  return 0;
}
