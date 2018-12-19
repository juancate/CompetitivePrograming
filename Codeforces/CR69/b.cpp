#include <bits/stdc++.h>

using namespace std;

int getmin(int m) {
  return m*6;
}

double gethour(int h, int m) {
  if(h >= 12) h -= 12;
  double angle = h*6*5;
  int min = getmin(m);
  angle += 30 * (min / 360.);
  return angle;
}

int main() {
  int h, m;
  scanf("%d:%d", &h, &m);

  cout << gethour(h,m) << " " <<  getmin(m) << endl;
  return 0;
}
