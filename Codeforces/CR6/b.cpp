#include <bits/stdc++.h>

using namespace std;

const int maxn = 111;

int n, m;
char b[maxn][maxn], c;

int dr[] = {0,1,0,-1};
int dc[] = {1,0,-1,0};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m >> c;
  for (int i = 0; i < n; i++)
    cin >> b[i];

  set<char> ans;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (b[i][j] == c) {
        for (int k = 0; k < 4; k++) {
          int ni = i + dr[k];
          int nj = j + dc[k];

          if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
            if (b[ni][nj] != '.' && b[ni][nj] != c)
              ans.insert(b[ni][nj]);
          }
        }
      }
    }
  }
  cout << ans.size() << '\n';

  return 0;
}
