#include <bits/stdc++.h>

using namespace std;

const int INF = (int)(1e9);

const int MAXG = 10010;

struct segment {
  int left, right;

  segment(int l = 0, int r = 0) {
    left = l, right = r;
  }

  bool operator<(const segment& a) const {
    if(left == a.left)
      return right > a.right;
    return left < a.left;
  }
} stations[MAXG];

int L, G;

int main() {
  int x, r;
  while (scanf("%d%d", &L, &G) && (L|G) != 0) {
    for (int i = 0; i < G; i++) {
      scanf("%d%d", &x, &r);
      stations[i].left = x-r; // pos
      stations[i].right = x+r; // reach
    }

    sort(stations, stations + G);

    int l = 0;
    int i = 0;
    int ans = 0;

    while (l < L) {
      segment best(INF, INF);
      while (i < G && stations[i].left <= l) {
        if ((best.left == INF && best.right == INF) ||
            best.right < stations[i].right)
          best = stations[i];
        i++;
      }

      if (best.left == INF && best.right == INF)
        break;
      ans++;
      l = best.right;
    }

    printf("%d\n", (l < L)? -1 : G - ans);
  }

  return 0;
}

