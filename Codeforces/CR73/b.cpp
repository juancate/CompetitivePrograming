#include <bits/stdc++.h>

using namespace std;

const int N = 33;

int n, m, x, dist[N][N], r[256], c[256];
string key[N];
vector<int> sx, sy;

inline int sqr(int y) {
  return y*y;
}

void calculate_dist() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      dist[i][j] = int(1e9);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < sx.size(); k++)
        dist[i][j] = min(dist[i][j], sqr(i - sx[k]) + sqr(j - sy[k]));
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char ch = key[i][j];
      if (r[ch] < 0 || dist[i][j] < dist[r[ch]][c[ch]])
        r[ch] = i, c[ch] = j;
    }
  }
}

int solve() {
  int q, ans = 0;
  string s;
  cin >> q >> s;

  for (int i = 0; i < q; i++) {
    if (isupper(s[i])) {
      s[i] = tolower(s[i]);
      if (r[s[i]] < 0 || c[s[i]] < 0 || sx.empty())
        return -1;

      if (dist[r[s[i]]][c[s[i]]] > x)
        ans++;
    }
    else {
      if (r[s[i]] < 0 || c[s[i]] < 0)
        return -1;
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m >> x;
  x *= x;

  memset(r, -1, sizeof r);
  memset(c, -1, sizeof c);

  for (int i = 0; i < n; i++) {
    cin >> key[i];
    for (int j = 0; j < m; j++) {
      if (key[i][j] == 'S') {
        sx.push_back(i);
        sy.push_back(j);
      }
    }
  }

  calculate_dist();
  cout << solve() << '\n';

  return 0;
}
