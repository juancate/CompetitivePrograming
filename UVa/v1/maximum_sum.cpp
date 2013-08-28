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

int mat[111][111];

int main() {
    int n;
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                scanf("%d", &mat[i][j]);

                if(i > 0) mat[i][j] += mat[i-1][j];
                if(j > 0) mat[i][j] += mat[i][j-1];

                if(i > 0 && j > 0) mat[i][j] -= mat[i-1][j-1];
            }
        }

        int max_subrect = -INF;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = i; k < n; k++) {
                    for(int l = j; l < n; l++) {
                        int subrect = mat[k][l];

                        if(i > 0) subrect -= mat[i-1][l];
                        if(j > 0) subrect -= mat[k][j-1];

                        if(i > 0 && j > 0) subrect += mat[i-1][j-1];

                        max_subrect = max(max_subrect, subrect);
                    }
                }
            }
        }

        printf("%d\n", max_subrect);
    }
}

