#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)

using namespace std;

const int MAXN = 1000 + 10;

char a[MAXN], b[MAXN];
int memo[MAXN][MAXN];

int main() {
    while(gets(a)) {
        gets(b);
        int n = strlen(a);
        int m = strlen(b);

        REP(i, 0, n) memo[i][0] = 0;
        REP(i, 0, m) memo[0][i] = 0;

        REP(i, 0, n) {
            REP(j, 0, m) {
                if(a[i] == b[j]) {
                    memo[i+1][j+1] = memo[i][j] + 1;
                } else {
                    memo[i+1][j+1] = max(memo[i][j+1], memo[i+1][j]);
                }
            }
        }

        printf("%d\n", memo[n][m]);
    }
}

