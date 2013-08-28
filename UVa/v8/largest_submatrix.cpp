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

const int MAXN = 26;

char line[MAXN];
int64 matrix[MAXN][MAXN];

int main() {
    int t, n;
    scanf("%d\n", &t);
    while(t--) {
        n = 1;
        REP(i, 0, n) {
            gets(line);
            n = strlen(line);

            REP(j, 0, n) {
                if(line[j] == '0')
                    matrix[i][j] = -INF;
                else
                    matrix[i][j] = 1;
                if(i > 0) matrix[i][j] += matrix[i-1][j];
                if(j > 0) matrix[i][j] += matrix[i][j-1];
                if(i > 0 && j > 0) matrix[i][j] -= matrix[i-1][j-1];
            }
        }
        gets(line);

        int64 max_submatrix = -INF;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = i; k < n; k++) {
                    for(int l = j; l < n; l++) {
                        int64 sub_matrix = matrix[k][l];

                        if(i > 0) sub_matrix -= matrix[i-1][l];
                        if(j > 0) sub_matrix -= matrix[k][j-1];
                        if(i > 0 && j > 0) sub_matrix += matrix[i-1][j-1];

                        max_submatrix = max(sub_matrix, max_submatrix);
                    }
                }
            }
        }

        if(max_submatrix < 0) max_submatrix = 0;
        printf("%d\n", max_submatrix);
        if(t) puts("");
    }
}

