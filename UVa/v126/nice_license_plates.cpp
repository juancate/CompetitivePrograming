#include <bits/stdc++.h>

using namespace std;

char s[10];

int main() {
  int n;
  scanf("%d", &n);

  while (n--) {
    scanf("%s", s);

    int let = 0, num = 0;
    for (int i = 2, k = 1; i >= 0; i--, k *= 26)
      let += (s[i] - 'A') * k;
    num = atoi(s+4);

    puts((abs(let - num) <= 100)? "nice" : "not nice");
  }

  return 0;
}
