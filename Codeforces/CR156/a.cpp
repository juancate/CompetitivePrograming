#include <bits/stdc++.h>

using namespace std;

int a[22], n, b[3];

int main() {
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
    b[i%3] += a[i];
  }

  if (b[0] > b[1] && b[0] > b[2]) puts("chest");
  else if (b[1] > b[0] && b[1] > b[2]) puts("biceps");
  else puts("back");

  return 0;
}
