#include <bits/stdc++.h>

using namespace std;

const int SIZE = 6;
int MOD;

const long long m[SIZE][SIZE] = {
  {2, 1, 1, 0, 1, 0},
  {1, 2, 0, 1, 1, 0},
  {1, 1, 1, 0, 1, 0},
  {1, 1, 0, 1, 1, 0},
  {0, 0, 0, 0, 1, 1},
  {0, 0, 0, 0, 0, 1}
};

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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, sx, sy, dx, dy;
  long long t;
  cin >> n >> sx >> sy >> dx >> dy >> t;

  MOD = n;

  Matrix a, b;

  memcpy(a.mat, m, sizeof m);

  b[0][0] = sx, b[1][0] = sy, b[2][0] = dx;
  b[3][0] = dy, b[4][0] = 0, b[5][0] = 1;

  a = pow(a, t) * b;
  long long x = a[0][0] % MOD, y = a[1][0] % MOD;

  if (x <= 0) x += MOD;
  if (y <= 0) y += MOD;
  cout << x << ' ' << y << '\n';

  return 0;
}
