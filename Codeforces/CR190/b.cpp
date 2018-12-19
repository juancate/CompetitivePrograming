#include <bits/stdc++.h>

using namespace std;

int a[3], b[3];

int solve() {
  int best = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++)
      b[j] = a[j];
    int curr = b[i] / 3;
    b[i] = b[i] % 3;
    int one = b[i];
    for (int j = 0; j < 3; j++)
      one = min(one, b[j]);
    curr += one;
    for (int j = 0; j < 3; j++)
      b[j] -= one;
    for (int j = 0; j < 3; j++)
      curr += b[j] / 3;
    best = max(best, curr);
  }
  return best;
}

int main() {
  for (int i = 0; i < 3; i++) {
    scanf("%d", a+i);
    b[i] = a[i];
  }

  int ans = 0;
  for (int i = 0; i < 3; i++) {
    ans += a[i] / 3;
    a[i] = a[i] % 3;
  }
  sort(a, a+3);
  ans += a[0];
  for (int i = 0; i < 3; i++)
    a[i] = b[i];
  printf("%d\n", max(ans, solve()));

  return 0;
}
