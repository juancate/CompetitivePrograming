#include <bits/stdc++.h>

using namespace std;

const int maxn = 50;

int N, p[maxn], rank[maxn];

void init(int n) {
  for (int i = 0; i < n; i++) {
    p[i] = i;
    rank[i] = 0;
  }
}

int find(int x) {
  return x == p[x] ? x : p[x] = find(p[x]);
}

void unite(int x, int y) {
  int px = find(x);
  int py = find(y);

  if (px == py)
    return;

  if (rank[px] < rank[py])
    p[px] = py;
  else {
    p[py] = px;
    if (rank[px] == rank[py])
      rank[px]++;
  }
}

int count_sets() {
  set<int> s;
  for (int i = 0; i < N; i++)
    s.insert(find(i));
  return s.size();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;
    cin.get();

    N = s[0] - 'A' + 1;
    init(N);

    while (getline(cin, s)) {
      if (s.empty())
        break;
      unite(s[0]-'A', s[1]-'A');
    }

    cout << count_sets() << '\n';

    if (t)
      cout << '\n';
  }

  return 0;
}
