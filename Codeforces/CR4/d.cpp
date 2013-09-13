#include <bits/stdc++.h>

using namespace std;

// Unsolved

const int maxn = 5010;

struct box {
  int w, h, index;
  box(int w=0, int h=0, int index=-1) :
    w(w), h(h), index(index) {}
};

int n, w, h;
box a[maxn];
bool g[maxn][maxn];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> w >> h;

  for (int i = 0; i < n; i++) {
    cin >> a[i].w >> a[i].h;
    a[i].index = i+1;
    for (int j = 0; j < i; j++) {
      if (a[j].w < a[i].w && a[j].h < a[j].h)
        g[i][j] = 1;
      if (a[i].w < a[j].w && a[i].h < a[i].h)
        g[j][i] = 1;
    }
  }

  return 0;
}
