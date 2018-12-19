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

int main() {
    int N, Q, cases = 1;
    while(scanf("%d%d", &N, &Q) && (N|Q)) {
        vector<int> marbles(N);
        REP(i, 0, N) scanf("%d", &marbles[i]);

        sort(ALL(marbles));

        printf("CASE# %d:\n", cases++);
        REP(i, 0, Q) {
            int x;
            scanf("%d", &x);
            int j = lower_bound(ALL(marbles), x) - marbles.begin();
            if(marbles[j] == x) {
                printf("%d found at %d\n", x, j+1);
            } else {
                printf("%d not found\n", x);
            }
        }
    }
}

