#include <bits/stdc++.h>

using namespace std;

int a[111];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; i++)
    scanf("%d", a+i);
  sort(a, a+n);

  int sum = 0, j = 0;
  while(m--) {
    if(sum + a[j] > sum)
      break;
    sum += a[j];
    j++;
  }

  printf("%d\n", abs(sum));

  return 0;
}
