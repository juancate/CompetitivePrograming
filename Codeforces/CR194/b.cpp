#include <bits/stdc++.h>

#define foreach(it,v) for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); it++)

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  set<int> x, y;
  set< pair<int,int> > points;

  for (int i = 0, xi, yi; i < 8; i++) {
    cin >> xi >> yi;
    x.insert(xi);
    y.insert(yi);

    points.insert(make_pair(xi,yi));
  }

  if (x.size() != 3 || y.size() != 3) {
    cout << "ugly\n";
    return 0;
  }

  int cnt = 0;
  vector<int> xx(x.begin(), x.end());
  vector<int> yy(y.begin(), y.end());

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (i == 1 && j == 1) continue;
      if (points.count(make_pair(xx[i], yy[j])))
        cnt++;
    }
  }

  if (cnt == 8)
    cout << "respectable\n";
  else
    cout << "ugly\n";

  return 0;
}
