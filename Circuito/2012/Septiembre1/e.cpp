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

#define D(x) cerr << #x << " = " << (x) << endl;
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long int64;

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

const int MAXN = 9;

int rows[MAXN+10][10], cols[MAXN+10][10];
char board[MAXN][20];

bool solved;
int R[90], C[90], m;

void bckt(int x) {
    if(x == m) {
        solved = true;
        return;
    }

    for(char ch = '1'; ch <= '9'; ch++) {
        if(rows[R[x]][ch - '0'] == 0 && cols[C[x]][ch - '0'] == 0) {
            board[R[x]][C[x]] = ch;

            rows[R[x]][ch - '0']++; cols[C[x]][ch - '0']++;

            bckt(x+1);
            if(solved) break;

            rows[R[x]][ch - '0']--; cols[C[x]][ch - '0']--;

            board[R[x]][C[x]] = '0';
        }
    }
}

int main() {
    int t; scanf("%d\n", &t);

    while(t--) {
        for(int i = 0; i < MAXN; i++)
            gets(board[i]);

        memset(rows, 0, sizeof(rows));
        memset(cols, 0, sizeof(cols));
        m = 0;

        for(int i = 0; i < MAXN; i++) {
            for(int j = 0; j < MAXN; j++) {
                int pos = board[i][j] - '0';

                if(board[i][j] == '0') {
                    R[m] = i; C[m] = j;
                    m++;
                    continue;
                }

                rows[i][pos]++; cols[j][pos]++;
            }
        }

        solved = true;

        for(int i = 1; i <= 9; i++) {
            for(int j = 1; j <= 9; j++) {
                if(rows[i][j] > 1 || cols[i][j] > 1) {
                    solved = false;
                }
            }
        }

        if(solved) {
            solved = false;
            bckt(0);
        }

        if(!solved) puts("Could not complete this grid.");
        else {
            for(int i = 0; i < 9; i++)
                puts(board[i]);
        }
        if(t) puts("");
    }
}

