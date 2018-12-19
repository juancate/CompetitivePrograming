#include <bits/stdc++.h>

using namespace std;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int a, b, n, px[111], py[111];
char s[111];

bool check(int x1, int y1, int x2, int y2) {
  long long mul = 0;

  if (x1 != 0)
    mul = x2 / x1;
  if (y1 != 0)
    mul = y2 / y1;

  if (mul < 0)
    return false;

  return (mul*x1 == x2) && (mul*y1 == y2);
}

bool solve() {
  for (int i = 0; i <= n; i++) {
    if (check(px[n], py[n], a-px[i], b-py[i]))
      return true;
  }
  return false;
}

int main() {
  scanf("%d%d", &a, &b);
  scanf("%s", s);

  n = strlen(s);

  px[0] = py[0] = 0;
  for (int i = 0; i < n; i++) {
    int op;
    switch(s[i]) {
      case 'U': op = 0; break;
      case 'R': op = 1; break;
      case 'D': op = 2; break;
      case 'L': op = 3; break;
    }
    px[i+1] = px[i] + dx[op];
    py[i+1] = py[i] + dy[op];
  }

  puts(solve()? "Yes" : "No");

  return 0;
}
