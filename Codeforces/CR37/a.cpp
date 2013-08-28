#include <bits/stdc++.h>

using namespace std;

int n, a[1000];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  sort(a,a+n);

  int total = 0, best = 0;
  for (int i = 0; i < n; i++) {
    int j = i+1;
    while (j < n && a[i] == a[j])
      j++;
    total++;
    best = max(best, j-i);
    i = j-1;
  }
  printf("%d %d\n", best, total);

  return 0;
}
