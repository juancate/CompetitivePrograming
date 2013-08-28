#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

char b[110][110];
vector<int> rows[110], cols[110];

int main() {
#ifdef LOCAL
  freopen("g.in", "r", stdin);
  freopen("g.out", "w", stdout);
#else
  ios_base::sync_with_stdio(false);
#endif

  int n;
  while(scanf("%d", &n)) {
    if(!n) break;
    for(int i = 0; i < n; i++) {
      scanf("%s", b[i]);
    }
    memset(rows, 0, sizeof rows);
    memset(cols, 0, sizeof cols);

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(b[i][j] == '.') continue;
        int cnt = 0;
        while(j < n && b[i][j] == 'X') {
          j++;
          cnt++;
        }
        j--;
        rows[i].push_back(cnt);
      }
      if(rows[i].empty()) rows[i].push_back(0);
    }

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(b[j][i] == '.') continue;
        int cnt = 0;
        while(j < n && b[j][i] == 'X') {
          j++;
          cnt++;
        }
        j--;
        cols[i].push_back(cnt);
      }
      if(cols[i].empty()) cols[i].push_back(0);
    }

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < rows[i].size(); j++) {
        if(j) printf(" ");
        printf("%d", rows[i][j]);
      }
      printf("\n");
    }
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < cols[i].size(); j++) {
        if(j) printf(" ");
        printf("%d", cols[i][j]);
      }
      printf("\n");
    }
  }

  return 0;
}
