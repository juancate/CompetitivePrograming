#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cassert>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <complex>

#define D(x) cerr << #x << " = " << (x) << endl;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

const int maxn = 111;

struct Rectangle {
  int xmin, ymin, xmax, ymax;
  Rectangle(int _xm = 0, int _ym = 0, int _xmx = 0, int _ymx = 0) {
  }
} rects[maxn];

bool g[maxn][maxn];
int n, area;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void fill_rect(int i) {
  for(int x = rects[i].xmin; x < rects[i].xmax; x++)
    for(int y = rects[i].ymin; y < rects[i].ymax; y++)
      g[y][x] = true;
}

bool valid(int x, int y) {
  return x >= 0 && x < maxn && y >= 0 && y < maxn;
}

void dfs(int x, int y) {
  if(!g[y][x])
    return;

  g[y][x] = false;
  area++;

  for(int k = 0; k < 4; k++) {
    int nx = x + dx[k];
    int ny = y + dy[k];
    if(valid(nx, ny)) {
      if(g[ny][nx])
        dfs(nx, ny);
    }
  }
}

int main() {
  int t;
  scanf("%d", &t);

  while(t--) {
    scanf("%d", &n);
    memset(g, 0, sizeof g);

    for(int i = 0; i < n; i++) {
      scanf("%d%d%d%d",
          &rects[i].xmin, &rects[i].ymin, &rects[i].xmax, &rects[i].ymax);
    }

    for(int i = 0; i < n; i++)
      fill_rect(i);

    area = 0;
    dfs(rects[0].xmin, rects[0].ymin);

    printf("%d\n", area);
    if(t) printf("\n");
  }

  return 0;
}

