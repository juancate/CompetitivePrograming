#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cassert>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <complex>

#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

const int SIZE = 100;
const int MOD = INF + 7;

struct Matrix {
    int mat[SIZE][SIZE];
    int n;

    Matrix(int n_ = 1) : n(n_) {
        memset(mat, 0, sizeof(mat));
    }

    int* operator[](int i) {
        return mat[i];
    }

    static Matrix identity(int n) {
        Matrix ans(n);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(i == j)
                    ans[i][j] = 1;

        return ans;
    }
};

Matrix operator*(Matrix a, Matrix b) {
    Matrix ans(a.n);

    for(int i = 0; i < a.n; i++) {
        for(int j = 0; j < a.n; j++) {
            int64 sum = 0;

            for(int k = 0; k < a.n; k++)
                sum += ((int64)a[i][k] * b[k][j]) % MOD;

            ans[i][j] = sum % MOD;
        }
    }
    return ans;
}

Matrix pow(Matrix a, int p) {
    Matrix ans = Matrix::identity(a.n);

    while(p > 0) {
        if(p & 1) ans = ans * a;
        a = a * a;
        p >>= 1;
    }

    return ans;
}

int main() {
    int c, l;
    while(scanf("%d%d", &c, &l) && (c|l)) {
        Matrix adj(c);

        REP(i, 0, l) {
            int x, y;
            scanf("%d%d", &x, &y);
            x--, y--;
            adj[x][y] = adj[y][x] = 1;
        }

        int s, e, d;
        scanf("%d%d%d", &s, &e, &d);
        s--, e--;

        adj = pow(adj, d);

        if(adj[s][e] != 0)
            puts("Yes, Teobaldo can travel.");
        else
            puts("No, Teobaldo can not travel.");
    }
}

