#include <bits/stdc++.h>

using namespace std;

int a[111];

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  sort(a, a+n);

  vector<int> v;
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    int j = i;

    while (j < n && a[i] == a[j]) {
      j++;
      cnt++;
    }

    v.push_back(cnt);
    i = j-1;
  }

  int m = v.size();
  int ans = 0;

  for (int i = 0; i < m; i++) {
    if (v[i] < 2) continue;
    while (v[i] >= 2) {
      v[i] -= 2;
      for (int j = i; j < m; j++) {
        if (v[j] >= 2) {
          ans++;
          v[j] -= 2;
          break;
        }
      }
    }
  }

  printf("%d\n", ans);

  return 0;
}
