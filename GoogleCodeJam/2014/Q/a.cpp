#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  for (int tc = 1; tc <= t; tc++) {
    int a, b;
    cin >> a;

    set<int> cards;
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        int x;
        cin >> x;
        if (i == a-1)
          cards.insert(x);
      }
    }

    cin >> b;

    int ans = 0, cnt = 0;
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        int x;
        cin >> x;
        if (i == b-1 && cards.count(x)) {
          ans = x;
          cnt++;
        }
      }
    }

    cout << "Case #" << tc << ": ";
    if (cnt == 0)
      cout << "Volunteer cheated!\n";
    else if (cnt > 1)
      cout << "Bad magician!\n";
    else
      cout << ans << '\n';
  }

  return 0;
}
