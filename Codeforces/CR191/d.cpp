#include <bits/stdc++.h>

using namespace std;

int n, m;
char s[555][555];
bool seen[555][555];

int dr[] = {1,0,-1,0};
int dc[] = {0,1,0,-1};

int pos;
char ta[1000000];
int ra[1000000], ca[1000000];

inline
bool valid(int r, int c) {
  return r >= 0 && r < n && c >= 0 && c < m && s[r][c] != '#';
}

void dfs(int r, int c, int rr, int rc) {
  if (seen[r][c])
    return;

  seen[r][c] = 1;
  ta[pos] = 'B', ra[pos] = r, ca[pos] = c;
  pos++;

  for (int i = 0; i < 4; i++) {
    int nr = r + dr[i];
    int nc = c + dc[i];
    if (valid(nr,nc))
      dfs(nr,nc,rr,rc);
  }

  if (!(r == rr && c == rc)) {
    ta[pos] = 'D', ra[pos] = r, ca[pos] = c;
    pos++;
    ta[pos] = 'R', ra[pos] = r, ca[pos] = c;
    pos++;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> s[i];

  pos = 0;
  memset(seen, 0, sizeof(seen));

  for (int r = 0; r < n; r++) {
    for (int c = 0; c < m; c++)
      if (!seen[r][c] && s[r][c] != '#')
        dfs(r,c,r,c);
  }

  cout << pos << endl;
  for (int i = 0; i < pos; i++) {
    cout << ta[i] << ' ' << ra[i]+1 << ' ' << ca[i]+1 << endl;
  }

  return 0;
}
