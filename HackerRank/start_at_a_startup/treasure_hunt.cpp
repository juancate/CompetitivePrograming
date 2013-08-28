#include <bits/stdc++.h>

using namespace std;

int tr, tc, g[6][6], parent[6][6];
bool seen[6][6];

bool bfs() {
  memset(seen, 0, sizeof(seen));
  memset(parent, -1, sizeof(parent));
  queue<int> q;
  q.push(11);
  seen[1][1] = true;

  while (!q.empty()) {
    int curr = q.front();
    q.pop();

    int r = curr / 10;
    int c = curr % 10;

    if (curr == g[r][c]) {
      tr = r;
      tc = c;
      return true;
    }

    int nr = g[r][c] / 10;
    int nc = g[r][c] % 10;
    if (!seen[nr][nc]) {
      seen[nr][nc] = true;
      parent[nr][nc] = curr;
      q.push(g[r][c]);
    }
  }
  return false;
}

void print(int r, int c) {
  if (parent[r][c] == -1) {
    cout << r << ' ' << c << '\n';
    return;
  }

  int pr = parent[r][c] / 10;
  int pc = parent[r][c] % 10;
  print(pr, pc);
  cout << r << ' ' << c << '\n';
}

void solve() {
  tr = tc = -1;
  if (bfs())
    print(tr, tc);
  else
    cout << "NO TREASURE\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  for (int i = 1; i <= 5; i++)
    for (int j = 1; j <= 5; j++)
      cin >> g[i][j];

  solve();

  return 0;
}
