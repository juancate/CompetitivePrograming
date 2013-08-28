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

int L, n;
int memo[55][55], seq[55];

int solve(int left, int rigth) {
    if(left == rigth - 1)
        return 0;

    if(memo[left][rigth] != -1)
        return memo[left][rigth];

    int ret = INF;

    for(int i = left+1; i < rigth; i++)
        ret = min(ret, solve(left, i) + solve(i, rigth) + (seq[rigth] - seq[left]));

    return memo[left][rigth] = ret;
}

int main() {
    while(~scanf("%d", &L) && L) {
        scanf("%d", &n);
        seq[0] = 0;
        n++;
        for(int i = 1; i < n; i++)
            scanf("%d", &seq[i]);
        seq[n] = L;
        n++;
        memset(memo, -1, sizeof(memo));

        printf("The minimum cutting is %d.\n", solve(0, n-1));
    }
}

