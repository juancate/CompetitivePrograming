#include <bits/stdc++.h>

using namespace std;

int n[2], T[2][1010];

void insert(int v) {
  int h = 0;
  while (true) {
    int hash = v % n[h];
    if (T[h][hash] == -1) {
      T[h][hash] = v;
      break;
    }
    swap(T[h][hash], v);
    h ^= 1;
  }
}

bool empty(int i) {
  for (int j = 0; j < n[i]; j++)
    if (T[i][j] != -1)
      return false;
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int m, tc = 1;
  while (cin >> n[0] >> n[1] >> m) {
    if ((n[0]|n[1]|m) == 0)
      break;

    memset(T, -1, sizeof T);
    for (int i = 0; i < m; i++) {
      int v;
      cin >> v;
      insert(v);
    }

    cout << "Case " << tc++ << ":\n";
    for (int i = 0; i < 2; i++) {
      if (empty(i))
        continue;

      cout << "Table " << (i+1) << '\n';
      for (int j = 0; j < n[i]; j++)
        if (T[i][j] != -1)
          cout << j << ':' << T[i][j] << '\n';
    }
  }

  return 0;
}
