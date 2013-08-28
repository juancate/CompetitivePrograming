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

const int INF = (int)(1e9);
const int64 INFLL = (int64)(1e18);
const double EPS = 1e-13;

struct box {
    int val;
    int dimensions[11];
} boxes[33];

int k, n, dp[33], sol[33];

bool fit(const box& a, const box& b) {
    for(int i = 0; i < n; i++) {
        if(a.dimensions[i] >= b.dimensions[i])
            return false;
    }
    return true;
}


void print(int i, bool first = false) {
    if(i == -1) return;

    print(sol[i]);

    printf("%d", (boxes[i].val+1));
    if(!first) printf(" ");
}

int main() {
    while(~scanf("%d%d", &k, &n)) {
        for(int i = 0; i < k; i++) {
            for(int j = 0; j < n; j++)
                scanf("%d", &boxes[i].dimensions[j]);

            boxes[i].val = i;
            sort(boxes[i].dimensions, boxes[i].dimensions + n);
        }

        for(int i = 0; i < k; i++) {
            for(int j = i+1; j < k; j++) {
                if(fit(boxes[j], boxes[i]))
                    swap(boxes[i], boxes[j]);
            }
        }

        fill(dp, dp+k, 1);
        memset(sol, -1, sizeof(sol));

        for(int i = 0; i < k; i++) {
            for(int j = 0; j < i; j++) {
                if(fit(boxes[j], boxes[i]) && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    sol[i] = j;
                }
            }
        }

        int best = 0;

        for(int i = 1; i < k; i++)
            if(dp[i] > dp[best])
                best = i;

        printf("%d\n", dp[best]);
        print(best, true);
        puts("");
    }
}

