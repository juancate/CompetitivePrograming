#include <bits/stdc++.h>

using namespace std;

int a[32][32], pos;
string s, t;

void paint(int lx, int rx, int ly, int ry) {
  char curr = s[pos++];

  if (curr == 'p') {
    int mx = (rx-lx+1) / 2, my = (ry-ly+1) / 2;
    paint(lx+mx, rx, ly, ly+my-1);
    paint(lx, lx+mx-1, ly, ly+my-1);
    paint(lx, lx+mx-1, ly+my, ry);
    paint(lx+mx, rx, ly+my, ry);
  }
  else if (curr == 'f') {
    for (int y = ly; y <= ry; y++)
      for (int x = lx; x <= rx; x++)
        a[y][x] = 1;
  }
}

int solve() {
  int r = 0;
  for (int i = 0; i < 32; i++)
    for (int j = 0; j < 32; j++)
      r += a[i][j];
  return r;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  while (N--) {
    memset(a, 0, sizeof(a));

    cin >> s;
    pos = 0;
    paint(0, 31, 0, 31);

    cin >> s;
    pos = 0;
    paint(0, 31, 0, 31);

    printf("There are %d black pixels.\n", solve());
  }

  return 0;
}
