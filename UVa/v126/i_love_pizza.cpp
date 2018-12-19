#include <bits/stdc++.h>

using namespace std;

int c[30];
char s[666];

const char* p = "MARGIT";

int main() {
  int n;
  scanf("%d", &n);

  while (n--) {
    scanf("%s", s);

    memset(c, 0, sizeof(c));

    for (int i = 0; s[i]; i++)
      c[s[i]-'A']++;

    c[0] /= 3;
    c['R'-'A'] /= 2;

    int ans = int(1e9);

    for (int i = 0; p[i]; i++)
      ans = min(ans, c[p[i]-'A']);

    printf("%d\n", ans);
  }

  return 0;
}
