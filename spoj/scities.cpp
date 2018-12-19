#include <bits/stdc++.h>

using namespace std;

const long long INF = int(1e9);
const int maxn = 110;

long long cost[maxn][maxn];
int n, max_match;
long long lx[maxn], ly[maxn], slack[maxn], slackx[maxn];
int xy[maxn], yx[maxn], prev[maxn];
bool S[maxn], T[maxn];

void init_labels() {
  memset(lx, 0, sizeof(lx));
  memset(ly, 0, sizeof(ly));
  for (int x = 0; x < n; x++)
    for (int y = 0; y < n; y++)
      lx[x] = max(lx[x], cost[x][y]);
}

void update_labels() {
  int x, y;
  long long delta = INF;
  for (y = 0; y < n; y++)
    if (!T[y])
      delta = min(delta, slack[y]);
  for (x = 0; x < n; x++)
    if (S[x]) lx[x] -= delta;
  for (y = 0; y < n; y++)
    if (T[y]) ly[y] += delta;
  for (y = 0; y < n; y++)
    if (!T[y])
      slack[y] -= delta;
}

void add_to_tree(int x, int prevx) {
  S[x] = true;
  prev[x] = prevx;
  for (int y = 0; y < n; y++)
    if (lx[x] + ly[y] - cost[x][y] < slack[y]) {
      slack[y] = lx[x] + ly[y] - cost[x][y];
      slackx[y] = x;
    }
}

void augment() {
  if (max_match == n) return; // match with small set
  int x, y, root;

  queue<int> q;

  memset(S, false, sizeof(S));
  memset(T, false, sizeof(T));
  memset(prev, -1, sizeof(prev));

  for (x = 0; x < n; x++) {
    if (xy[x] == -1) {
      root = x;
      q.push(root);
      prev[x] = -2;
      S[x] = true;
      break;
    }
  }

  for (y = 0; y < n; y++) {
    slack[y] = lx[root] + ly[y] - cost[root][y];
    slackx[y] = root;
  }

  while (true) {
    while (!q.empty()) {
      x = q.front();
      q.pop();
      for (y = 0; y < n; y++) {
        if (cost[x][y] == lx[x] + ly[y] && !T[y]) {
          if (yx[y] == -1) break;

          T[y] = true;
          q.push(yx[y]);

          add_to_tree(yx[y], x);
        }
      }
      if (y < n) break;
    }
    if (y < n) break;

    update_labels();
    while (!q.empty()) q.pop();

    for (y = 0; y < n; y++) {
      if (!T[y] && slack[y] == 0) {
        if (yx[y] == -1) {
          x = slackx[y];
          break;
        }
        else {
          T[y] = true;
          if (!S[yx[y]]) {
            q.push(yx[y]);
            add_to_tree(yx[y], slackx[y]);
          }
        }
      }
    }
    if (y < n) break;
  }

  if (y < n) {
    max_match++;

    for (int cx = x, cy = y, ty; cx != -2; cx = prev[cx], cy = ty) {
      ty = xy[cx];
      yx[cy] = cx;
      xy[cx] = cy;
    }
    augment();
  }
}

long long hungarian() {
  long long ret = 0;
  max_match = 0;
  memset(xy, -1, sizeof(xy));
  memset(yx, -1, sizeof(yx));
  init_labels();
  augment();
  for (int x = 0; x < n; x++)
    ret += cost[x][xy[x]];
  return ret;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    int c1, c2, g;
    cin >> c1 >> c2;

    n = max(c1, c2);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        cost[i][j] = 0;

    while(true) {
      cin >> c1 >> c2 >> g;
      if ((c1|c2|g) == 0)
        break;
      cost[c1-1][c2-1] = g;
    }

    cout << hungarian() << '\n';
  }

  return 0;
}
