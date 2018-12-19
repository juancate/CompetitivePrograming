#include <cstdio>

int main() {
#ifdef LOCAL
  freopen("e.in", "r", stdin);
  freopen("e.out", "w", stdout);
#endif

  int n, w, l, h, a, m;

  while(scanf("%d%d%d%d%d%d", &n, &w, &l, &h, &a, &m)) {
    if(!(n|w|l|h|a|m)) break;

    long long total = w*h*2 + l*h*2 + l*w;
    while(m--) {
      int x, y;
      scanf("%d%d", &x, &y);
      total -= (x * y);
    }
    total *= n;
    int ans = total / a;
    if(total % a) ans++;
    printf("%d\n", ans);
  }

  return 0;
}
