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
#include <set>
#include <map>
#include <algorithm>

#define D(x) cerr << #x << " = " << x << endl
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

using namespace std;

int MOD = INF + 7;

const int SIZE = 52;

struct Matrix {
    int64 mat[SIZE][SIZE];
    int n;

    Matrix() {
        n = SIZE;
        memset(mat, 0, sizeof(mat));
    }

    int64* operator[](int i) {
        return mat[i];
    }

    static Matrix identity(int n) {
        Matrix ans;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(i == j)
                    ans[i][j] = 1;

        return ans;
    }
};

Matrix operator*(Matrix a, Matrix b) {
    Matrix ans;

    for(int i = 0; i < a.n; i++) {
        for(int j = 0; j < a.n; j++) {
            int64 sum = 0;

            for(int k = 0; k < a.n; k++) {
                sum += ((int64)a[i][k] * b[k][j]) % MOD;
            }

            ans[i][j] = sum % MOD;
        }
    }
    return ans;
}

Matrix pow(Matrix a, int64 p) {
    Matrix ans = Matrix::identity(a.n);

    while(p > 0) {
        if(p & 1) ans = ans * a;
        a = a * a;
        p >>= 1;
    }

    return ans;
}

int getcode(char c) {
    if(islower(c)) return c - 'a';
    return c - 'A' + 26;
}

int main() {
    ios_base::sync_with_stdio(false);

    int64 n;
    int m, k;
    cin >> n >> m >> k;

    Matrix a;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            a[i][j] = 1;
        }
    }

    for(int i = 0; i < k; i++) {
        string s; cin >> s;

        a[getcode(s[0])][getcode(s[1])] = 0;
    }

    a = pow(a, n-1);

    int64 ans = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++)
            ans += a[i][j];
    }

    cout << ans%MOD << endl;
}

