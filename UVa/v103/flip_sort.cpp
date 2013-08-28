#include <bits/stdc++.h>

using namespace std;

int a[1010];

int main() {
  int n;
  while(~scanf("%d", &n)) {
    for(int i = 0; i < n; i++)
      scanf("%d", a+i);

    int ans = 0;
    for(int i = 0; i < n; i++) {
      for(int j = i+1; j < n; j++)
        if(a[j] < a[i]) {
          ans++;
        }
    }
    printf("Minimum exchange operations : %d\n", ans);
  }
  return 0;
}
