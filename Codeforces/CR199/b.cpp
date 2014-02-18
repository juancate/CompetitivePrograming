#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m, s, f, t[N], l[N], r[N];

bool cant_move(int li, int ri, int x, int d) {
  return (li <= x && x <= ri) || (li <= (x+d) && (x+d) <= ri);
}

string solve() {
  if (s == f)
    return "X";

  int dir = (s <= f)? 1 : -1;

  int curr_t = 1, pos = s;
  string ans;

  for (int i = 0; i < m && pos != f; i++) {
    while (curr_t < t[i] && pos != f) {
      ans.push_back((dir < 0? 'L' : 'R'));
      pos += dir;
      curr_t++;
    }

    if (pos == f)
      break;

    if (!cant_move(l[i], r[i], pos, dir)) {
      ans.push_back((dir < 0? 'L' : 'R'));
      pos += dir;
    }
    else {
      ans.push_back('X');
    }
    curr_t++;
  }

  while (pos != f) {
    ans.push_back((dir < 0? 'L' : 'R'));
    pos += dir;
  }

  return ans;
}

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m >> s >> f;

  for (int i = 0; i < m; i++)
    cin >> t[i] >> l[i] >> r[i];

  cout << solve() << '\n';

  return 0;
}
