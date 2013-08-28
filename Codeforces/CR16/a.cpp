#include <bits/stdc++.h>

using namespace std;

char b[111][111];

bool solve(int n, int m) {
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m-1; j++)
      if(b[i][j] != b[i][j+1])
        return false;

  for(int i = 0; i < n-1; i++)
    if(b[i][0] == b[i+1][0])
      return false;

  return true;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 0; i < n; i++)
    scanf("%s", b[i]);

  puts(solve(n, m)? "YES" : "NO");

  return 0;
}
