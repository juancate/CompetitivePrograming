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

const int MAXN = 80;

int board[MAXN][MAXN+MAXN], sum[MAXN+MAXN], n;

int kadane(int& l, int& r) {
    int max_sum = -1, current_sum = 0;

    for(int i = 0, j = 0; j < n + n; j++) {
        current_sum += sum[j];
        if(current_sum > max_sum) {
            max_sum = current_sum;
            l = i, r = j;
        }

        if(current_sum < 0) {
            current_sum = 0;
            i = j+1;
        }
    }

    return max_sum;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        REP(i, 0, n) REP(j, 0, n) scanf("%d", &board[i][j]);

        REP(i, 0, n) REP(j, n, n+n) board[i][j] = board[i][j-n];

        int ans = -1;
        int x1, y1, x2, y2;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n+n; j++)
                sum[j] = 0;

            for(int j = i; j < n + n; j++) {

                for(int k = 0; k < n+n; k++)
                    sum[k] += board[j % n][k];


                cerr << "j = " << j << endl;
                for(int k = 0; k < n+n; k++)
                    cerr << sum[k] << ' ';
                cerr << endl;

                int tx1, tx2;
                int current = kadane(tx1, tx2);

                if(current > ans) {
                    ans = current;
                    y1 = tx1, y2 = tx2;
                    x1 = i, x2 = j % n;
                }
            }
        }
        cerr << "x1 = " << x1 << " y1 = " << y1 << " x2 = " << x2 << " y2 = " << y2 << endl;
        printf("%d\n", ans);
    }
}

