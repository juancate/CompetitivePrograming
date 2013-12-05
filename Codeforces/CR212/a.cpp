#include <bits/stdc++.h>

#define foreach(it,v) \
  for (__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)

using namespace std;

string g[10];
bool seen[10][10][10][10];

int m1[] = {2, 2, -2, -2};
int m2[] = {-2, 2, -2, 2};

struct state {
  int r1, c1, r2, c2;
  state(int r1=0, int c1=0, int r2=0, int c2=0) :
    r1(r1), c1(c1), r2(r2), c2(c2) {}
};

bool valid(int r, int c) {
  return r >= 0 && r < 8 && c >= 0 && c < 8;
}

bool bfs(int kr1, int kc1, int kr2, int kc2) {
  memset(seen, 0, sizeof seen);
  queue<state> q;
  q.push(state(kr1,kc1,kr2,kc2));
  seen[kr1][kc1][kr2][kc2] = true;

  while (!q.empty()) {
    state s = q.front();
    q.pop();

    int r1 = s.r1;
    int c1 = s.c1;
    int r2 = s.r2;
    int c2 = s.c2;

    if (r1 == r2 && c1 == c2 && g[r1][c1] == '.') {
      return true;
    }

    for (int i = 0; i < 4; i++) {
      int nr1 = m1[i] + r1;
      int nc1 = m2[i] + c1;

      if (valid(nr1, nc1)) {
        for (int j = 0; j < 4; j++) {
          int nr2 = m1[j] + r2;
          int nc2 = m2[j] + c2;

          if (valid(nr2, nc2) && !seen[nr1][nc1][nr2][nc2]) {
            seen[nr1][nc1][nr2][nc2] = true;
            q.push(state(nr1,nc1,nr2,nc2));
          }
        }
      }
    }
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    int kr1 = -1, kc1 = -1, kr2, kc2;
    for (int i = 0; i < 8; i++) {
      cin >> g[i];
      for (int j = 0; j < 8; j++) {
        if (g[i][j] == 'K') {
          if (kr1 < 0)
            kr1 = i, kc1 = j;
          else
            kr2 = i, kc2 = j;
          g[i][j] = '.';
        }
      }
    }

    if (bfs(kr1, kc1, kr2, kc2))
      cout << "YES\n";
    else
      cout << "NO\n";
  }

  return 0;
}

