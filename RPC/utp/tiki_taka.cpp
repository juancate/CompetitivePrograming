#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;
const int SIZE = 11;

long long N, K, L;

struct Matrix {
  long long mat[SIZE][SIZE];
  int n;

  Matrix() {
    n = SIZE;
    memset(mat, 0, sizeof(mat));
  }

  long long* operator[](int i) {
    return mat[i];
  }

  static Matrix identity(int n) {
    Matrix ans;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (i == j)
          ans[i][j] = 1;
    return ans;
  }
};

Matrix operator*(Matrix a, Matrix b) {
  Matrix ans;
  for (int i = 0; i < a.n; i++) {
    for (int j = 0; j < a.n; j++) {
      long long sum = 0;
      for (int k = 0; k < a.n; k++)
        sum += ((long long)a[i][k] * b[k][j]) % MOD;
      ans[i][j] = sum % MOD;
    }
  }
  return ans;
}

Matrix pow(Matrix a, long long p) {
  Matrix ans = Matrix::identity(a.n);

  while (p > 0) {
    if (p & 1) ans = ans * a;
    a = a * a;
    p >>= 1;
  }
  return ans;
}


int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  for (int tc = 1; tc <= t; tc++) {
    Matrix a;
    int p, l;
    cin >> p >> l;

    for (int i = 0; i < l; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      a[u][v] = 1;
    }

    int q;
    cin >> q;

    cout << "Case " << tc << ":\n";
    while (q--) {
      int u, v;
      long long n;
      cin >> u >> v >> n;
      u--, v--;

      Matrix b = pow(a, n);
      cout << b[u][v] << '\n';
    }
  }

  return 0;
}