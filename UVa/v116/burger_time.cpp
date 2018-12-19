#include <bits/stdc++.h>

using namespace std;

const int inf = int(1e9);

char s[2000010];

int main() {
  int n;

  while(scanf("%d", &n)) {
    if (n == 0)
      break;
    scanf("%s", s);

    int best = inf, pos = -1;

    for (int i = 0; i < n; i++) {
      if (s[i] == 'R')
        pos = i;
      else if (s[i] == 'D' && pos != -1)
        best = min(best, i-pos);
      else if (s[i] == 'Z')
        best = 0;
    }

    pos = -1;
    for (int i = n-1; i >= 0; i--) {
      if (s[i] == 'R')
        pos = i;
      else if (s[i] == 'D' && pos != -1)
        best = min(best, pos-i);
      else if (s[i] == 'Z')
        best = 0;
    }

    printf("%d\n", best);
  }

  return 0;
}
