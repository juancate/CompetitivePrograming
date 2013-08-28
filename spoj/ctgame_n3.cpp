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
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define FOREACH(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define ALL(v) (v).begin(), (v).end()

using namespace std;


typedef long long int64;

const int INF = int(1e9);
const int64 INFLL = int64(1e18);
const double EPS = 1e-13;

const int MAXH = 1000 + 10;
const int MAXW = 1000 + 10;

int K, H, W;
char board[MAXH];
int data[MAXH][MAXW];
int64 sum[MAXH];

int64 kadane(int& l, int& r) {
    int64 current_sum = 0, max_sum = 0;

    for(int i = 0, j = 0; j < W; j++) {
        current_sum += sum[j];

        if(current_sum > max_sum) {
            max_sum = current_sum;
            r = j;
            l = i;
        }

        if(current_sum < 0) {
            current_sum = 0;
            i = j+1;
        }
    }

    return max_sum;
}

int main() {
    //sscanf(gets(board), "%d", &K);
    scanf("%d", &K);
    while (K--) {
        //sscanf(gets(board), "%d%d", &H, &W);
        scanf("%d%d", &H, &W);

        REP(i, 0, H) {
            //gets(board);
            int j = 0;
            for(int k = 0; k < W; k++) {
                scanf("%s", board);

                assert(board[0] == 'F' || board[0] == 'R');

                if(board[0] == 'R') data[i][j] = -INF;
                if(board[0] == 'F') data[i][j] = 1;

                j++;
            }
        }
        //if(K) gets(board);

        int x1, y1, x2, y2;
        x1 = y1 = x2 = y2 = -1;
        int64 ans = -INF, current_sum = -1;

        for(int i = 0; i < H; i++) {
            for(int j = 0; j < W; j++)
                sum[j] = 0;

            for(int j = i; j < H; j++) {
                for(int k = 0; k < W; k++)
                    sum[k] += data[j][k];

                int tx1, tx2;
                current_sum = kadane(tx1, tx2);
                if(current_sum > ans) {
                    y1 = tx1;
                    y2 = tx2;
                    x1 = i;
                    x2 = j;
                    ans = current_sum;
                }
            }
        }

        if(ans < 0) ans = 0;
        printf("%lld\n", 3*ans);
    }
}

