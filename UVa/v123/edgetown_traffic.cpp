#include <bits/stdc++.h>

using namespace std;

const int INF = (int)1e9;

int g1[111][111], g2[111][111], n, A, B;

void run_floyd() {
  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        g1[i][j] = min(g1[i][j], g1[i][k] + g1[k][j]);
        g2[i][j] = min(g2[i][j], g2[i][k] + g2[k][j]);
      }
}

bool check() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      if (g2[i][j] > A*g1[i][j] + B)
        return false;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);

  while (cin >> n) {
    if (n == 0)
      break;
    cin.ignore();
    string ln;

    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        g1[i][j] = g2[i][j] = INF;

    for (int i = 0, u, v; i < n; i++) {
      getline(cin, ln);
      stringstream ss(ln);
      ss >> u;

      while (ss >> v)
        g1[u-1][v-1] = 1;
    }

    for (int i = 0, u, v; i < n; i++) {
      getline(cin, ln);
      stringstream ss(ln);
      ss >> u;

      while (ss >> v)
        g2[u-1][v-1] = 1;
    }
    cin >> A >> B;

    run_floyd();
    puts(check()? "Yes" : "No");
  }

  return 0;
}
