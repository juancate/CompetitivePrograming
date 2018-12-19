#include <bits/stdc++.h>

using namespace std;

const int INF = int(1e9);

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  int l = -2 * INF, r = 2 * INF;

  while (n--) {
    string op, ans;
    int num;
    cin >> op >> num >> ans;

    if (op == ">") {
      if (ans == "Y") l = max(l, num+1);
      else r = min(r, num);
    }
    else if (op == ">=") {
      if (ans == "Y") l = max(l, num);
      else r = min(r, num-1);
    }
    else if (op == "<") {
      if (ans == "Y") r = min(r, num-1);
      else l = max(l, num);
    }
    else if (op == "<=") {
      if (ans == "Y") r = min(r, num);
      else l = max(l, num+1);
    }
  }

  if (l > r) cout << "Impossible" << '\n';
  else cout << l << '\n';

  return 0;
}
