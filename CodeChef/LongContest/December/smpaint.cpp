#include <bits/stdc++.h>

using namespace std;

const int INF = int(1e9);
const int N = 1010;

const int dr[] = {1, 0, -1, 0};
const int dc[] = {0, 1, 0, -1};

int n, paint[N][N], paint2[N][N];
bool seen[N][N];

int x_min, x_max, y_min, y_max;

bool can(int i, int j, int sz) {
  for (int ii = 0; ii < sz; ii++)
    if (paint[i][j] != paint[i+ii][j+sz-1])
      return false;
  for (int jj = 0; jj < sz; jj++)
    if (paint[i][j] != paint[i+sz-1][j+jj])
      return false;
  return true;
}

int get_size(int i, int j) {
  int sz = 0;

  while (can(i, j, sz+1)) {
    for (int ii = 0; ii < sz; ii++)
      seen[i+ii][j+sz-1] = true;
    for (int jj = 0; jj < sz; jj++)
      seen[i+sz-1][j+jj] = true;
    sz++;
  }

  return sz;
}

void dfs(int i, int j) {
  if (seen[i][j])
    return;

  seen[i][j] = true;
  x_min = min(x_min, i);
  x_max = max(x_max, i);
  y_min = min(y_min, j);
  y_max = max(y_max, j);

  for (int k = 0; k < 4; k++) {
    int ni = i + dr[k];
    int nj = j + dc[k];

    if (ni >= 0 && ni < n && nj >= 0 && nj < n)
      if (paint[ni][nj] == paint[i][j])
        dfs(ni, nj);
  }
}

struct answer {
  int xmin, ymin, xmax, ymax, color;
  answer(int x1=0, int x2=0, int y1=0, int y2=0, int c=0) :
    xmin(x1), xmax(x2), ymin(y1), ymax(y2), color(c) {
  }

  int area() const {
    return abs(x_max - x_min) * abs(y_max - y_min);
  }

  bool operator<(const answer& other) const {
    return area() < other.area();
  }
};

void check(const vector<answer> & ans) {
  assert(ans.size() <= (n * n));
  memset(paint2, 0, sizeof paint2);
  int m = ans.size();
  int prev = -1;

  for (int k = 0; k < m; k++) {
    int c, u, d, l, r;
    c = ans[k].color;
    u = ans[k].xmin;
    d = ans[k].xmax;
    l = ans[k].ymin;
    r = ans[k].ymax;

    for (int i = u; i <= d; i++)
      for (int j = l; j <= r; j++)
        paint2[i][j] = c;
  }

  cerr << "===========\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cerr << paint2[i][j] << ' ';
    cerr << '\n';
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      assert(paint[i][j] == paint2[i][j]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> paint[i][j];

  memset(seen, 0, sizeof seen);

  vector<answer> ans;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (!seen[i][j] && paint[i][j] != 0) {
        //x_min = y_min = INF;
        //x_max = y_max = -INF;
        //dfs(i, j);
        int sz = get_size(i, j);
        x_min = i, x_max = i+sz-1;
        y_min = j, y_max = j+sz-1;
        ans.push_back(answer(x_min, x_max, y_min, y_max, paint[i][j]));
      }
    }
  }
  sort(ans.rbegin(), ans.rend());

  //check(ans);
  cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); i++) {
    answer & c = ans[i];
    cout << c.color << ' ' << c.xmin+1 << ' ' << c.xmax+1
         << ' ' << c.ymin+1 << ' ' << c.ymax+1 << '\n';
  }

  return 0;
}
