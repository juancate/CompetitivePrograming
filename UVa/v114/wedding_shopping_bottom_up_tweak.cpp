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

int T, M, C, price[25][25];
bool can_reach[2][210];

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &M, &C);

        for(int i = 0; i < C; i++) {
            scanf("%d", &price[i][0]);
            for(int j = 1; j <= price[i][0]; j++)
                scanf("%d", &price[i][j]);
        }

        memset(can_reach, false, sizeof(can_reach));

        for(int i = 1; i <= price[0][0]; i++)
            can_reach[0][M - price[0][i]] = true;

        int prev = 0, current = 1;

        for(int j = 1; j < C; j++) {
            for(int i = 0; i < M; i++) {
                if(can_reach[prev][i]) {
                    for(int l = 1; l <= price[j][0]; l++) {
                        if(i - price[j][l] >= 0) {
                            can_reach[current][i - price[j][l]] = true;
                        }
                    }
                }
                can_reach[prev][i] = false;
            }
            prev = current;
            current ^= 1;
        }

        int money = 0;
        for(money = 0; money <= M && !can_reach[prev][money]; money++);

        if(money > M) puts("no solution");
        else printf("%d\n", M - money);
    }
}

